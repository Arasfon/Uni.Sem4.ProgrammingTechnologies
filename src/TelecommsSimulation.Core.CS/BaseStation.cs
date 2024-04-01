using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;

using TelecommsSimulation.Utilities;

namespace TelecommsSimulation.Core;

public class BaseStation : ILocatable, INotifyPropertyChanged
{
    protected readonly ConcurrentDictionary<string, Phone> ConnectedPhonesMap = [];

    // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
    // Hack: Also should be private, but it's public for the sake of connection visualization
    public IEnumerable<Phone> ConnectedPhones => ConnectedPhonesMap.Values.ToImmutableArray();

    protected static readonly ConcurrentDictionary<string, CallPhoneData> CallDataLookupDictionary = [];

    // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
    // Hack: Also should not exist at all, but exists for the sake of calls visualization
    public static IEnumerable<CallPhoneData> CurrentCalls => CallDataLookupDictionary.Values.ToImmutableArray().Distinct();

    public string Name { get; }

    private bool _isEnabled;

    public bool IsEnabled
    {
        get => _isEnabled;
        private set => SetField(ref _isEnabled, value);
    }

    public Coordinates Location { get; }

    public double CoverageRadiusKm { get; }

    public int ConnectedPhonesCount => ConnectedPhonesMap.Count;

    protected static readonly List<BaseStation> AllEnabledStationsList = [];

    // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
    public static IEnumerable<BaseStation> AllEnabledStations => AllEnabledStationsList.ToImmutableArray();

    protected readonly SynchronizationContext? UiSynchronizationContext;

    public BaseStation(string name, Coordinates location, double coverageRadiusKm)
    {
        UiSynchronizationContext = SynchronizationContext.Current;

        Name = name;
        Location = location;
        CoverageRadiusKm = coverageRadiusKm;
    }

    public virtual void Enable()
    {
        if (IsEnabled)
            throw new InvalidBaseStationStateException();

        IsEnabled = true;
        AllEnabledStationsList.Add(this);
    }

    public virtual void Disable()
    {
        if (!IsEnabled)
            throw new InvalidBaseStationStateException();

        AllEnabledStationsList.Remove(this);

        foreach (KeyValuePair<string, Phone> connectedPhonePair in ConnectedPhonesMap)
            connectedPhonePair.Value.SwitchBaseStationIfNeeded();

        IsEnabled = false;
    }

    public virtual void RegisterPhone(Phone phone)
    {
        if (FindPhone(phone.Number) is not null)
            throw new Exception("This number is already connected");

        if (!ConnectedPhonesMap.TryAdd(phone.Number, phone))
            throw new Exception("This number is already connected");

        OnPropertyChanged(nameof(ConnectedPhonesCount));
        OnPropertyChanged(nameof(ConnectedPhones));

        phone.CallEnded += CallEnded;
    }

    public virtual void UnregisterPhone(Phone phone)
    {
        ConnectedPhonesMap.Remove(phone.Number, out _);

        OnPropertyChanged(nameof(ConnectedPhonesCount));
        OnPropertyChanged(nameof(ConnectedPhones));

        phone.CallEnded -= CallEnded;
    }

    public virtual async Task<CallResult> InitiateCall(Phone caller, string to)
    {
        Phone? receiverPhone = FindPhone(to);

        if (receiverPhone is null)
            return CallResult.NotFound;

        if (receiverPhone.CallState is not CallState.Idle)
            return CallResult.Busy;

        CallPhoneData callPhoneData = new(caller, receiverPhone);

        if (!CallDataLookupDictionary.TryAdd(to, callPhoneData))
            return CallResult.Busy;

        bool callerAdded = CallDataLookupDictionary.TryAdd(caller.Number, callPhoneData);

        Debug.Assert(callerAdded);

        CallAnswer callAnswer;

        try
        {
            callAnswer = await receiverPhone.ReceiveCall(caller.Number);
        }
        catch (OperationCanceledException)
        {
            CallDataLookupDictionary.TryRemove(caller.Number, out _);
            CallDataLookupDictionary.TryRemove(to, out _);
            return CallResult.Busy;
        }

        switch (callAnswer)
        {
            case CallAnswer.Agreed:
            {
                return CallResult.Established;
            }
            case CallAnswer.Declined:
            {
                CallDataLookupDictionary.TryRemove(caller.Number, out _);
                CallDataLookupDictionary.TryRemove(to, out _);
                return CallResult.Busy;
            }
            default:
            {
                CallDataLookupDictionary.TryRemove(caller.Number, out _);
                CallDataLookupDictionary.TryRemove(to, out _);
                throw new ArgumentOutOfRangeException(null, "Call answer was out of range");
            }
        }
    }

    protected void CallEnded(object? sender, CallEventArgs e)
    {
        if (!CallDataLookupDictionary.Remove(e.CallerNumber, out CallPhoneData? callData))
            return;

        Debug.Assert(callData is not null);

        bool receiverRemoved = CallDataLookupDictionary.Remove(e.ReceiverNumber, out _);

        Debug.Assert(receiverRemoved);

        callData!.Caller.EndCall();
        callData.Receiver.EndCall();
    }

    protected static Phone? FindPhone(string number)
    {
        Phone? phone = null;
        foreach (BaseStation baseStation in AllEnabledStations)
        {
            if (baseStation.ConnectedPhonesMap.TryGetValue(number, out phone))
                break;
        }

        return phone;
    }

    public event PropertyChangedEventHandler? PropertyChanged;

    protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null)
    {
        // Workaround: WinForms' lack of threading awareness and the challenge of re-invoking handlers in C++/CLI (i.e. no support for lambda-functions)
        if (UiSynchronizationContext != null)
            UiSynchronizationContext.Post(_ => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName)), null);
        else
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }

    protected bool SetField<T>(ref T field, T value, [CallerMemberName] string? propertyName = null)
    {
        if (EqualityComparer<T>.Default.Equals(field, value))
            return false;
        field = value;
        OnPropertyChanged(propertyName);
        return true;
    }
}
