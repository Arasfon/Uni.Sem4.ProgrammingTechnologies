using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;

using TelecommsSimulation.Utilities;

namespace TelecommsSimulation.Core;

public class Phone : ILocatableMovable, INotifyPropertyChanged
{
    public string Number { get; }

    private Coordinates _location;

    public Coordinates Location
    {
        get => _location;
        set
        {
            SetField(ref _location, value);
            SwitchBaseStationIfNeeded();
        }
    }

    private PhoneState _state = PhoneState.Off;

    public PhoneState State
    {
        get => _state;
        private set => SetField(ref _state, value);
    }

    private CallState _callState = CallState.Idle;

    public CallState CallState
    {
        get => _callState;
        private set => SetField(ref _callState, value);
    }

    private string? _inCallWith;

    public string? InCallWith
    {
        get => _inCallWith;
        private set => SetField(ref _inCallWith, value);
    }

    private double _batteryLevel;

    public double BatteryLevel
    {
        get => _batteryLevel;
        set => SetField(ref _batteryLevel, MathExtensions.Clamp(value, 0, 100));
    }

    protected BaseStation? ConnectedBaseStation;

    public string? ConnectedBaseStationName => ConnectedBaseStation?.Name;

    protected readonly SynchronizationContext? UiSynchronizationContext;

    protected TaskCompletionSource<CallAnswer>? CallAnswerCompletionSource;

    public event EventHandler? Connected;
    public event EventHandler? Disconnected;
    public event AsyncEventHandler<CallEventArgs>? CallReceived;
    public event EventHandler<CallEventArgs>? CallEnded;

    public Phone(string number, Coordinates location, double batteryLevel = 100)
    {
        UiSynchronizationContext = SynchronizationContext.Current;

        Number = number;
        Location = location;
        BatteryLevel = batteryLevel;
    }

    public virtual void TurnOn()
    {
        if (State is not PhoneState.Off)
            throw new InvalidPhoneStateException();

        if (BatteryLevel == 0)
            return;

        State = PhoneState.Disconnected;
    }

    public virtual void TurnOff()
    {
        if (State is PhoneState.Off)
            throw new InvalidPhoneStateException();

        if (State is PhoneState.Connected)
            DisconnectFromBaseStation();

        State = PhoneState.Off;
    }

    public virtual void ConnectToBaseStation()
    {
        switch (State)
        {
            case PhoneState.Off:
            {
                throw new InvalidPhoneStateException();
            }
            case PhoneState.Connected:
            {
                DisconnectFromBaseStation();
                break;
            }
        }

        BaseStation? nearestStation = FindBaseStation();

        if (nearestStation is null)
            return;

        nearestStation.RegisterPhone(this);
        ConnectedBaseStation = nearestStation;
        OnPropertyChanged(nameof(ConnectedBaseStationName));

        State = PhoneState.Connected;
        Connected?.Invoke(this, EventArgs.Empty);
    }

    public virtual void DisconnectFromBaseStation()
    {
        if (State is not PhoneState.Connected)
            throw new InvalidPhoneStateException();

        if (CallState is not CallState.Idle)
            EndCall();

        ConnectedBaseStation!.UnregisterPhone(this);
        ConnectedBaseStation = null;
        OnPropertyChanged(nameof(ConnectedBaseStationName));

        State = PhoneState.Disconnected;
        Disconnected?.Invoke(this, EventArgs.Empty);
    }

    public virtual void SwitchBaseStationIfNeeded()
    {
        if (State is not PhoneState.Connected)
            return;

        if (ConnectedBaseStation!.IsEnabled && IsCoveredBy(ConnectedBaseStation!))
            return;

        BaseStation? nearestStation = FindBaseStation();

        if (nearestStation is null)
        {
            DisconnectFromBaseStation();
            return;
        }

        ConnectedBaseStation!.UnregisterPhone(this);

        nearestStation.RegisterPhone(this);

        ConnectedBaseStation = nearestStation;
        OnPropertyChanged(nameof(ConnectedBaseStationName));
    }

    public virtual async Task<CallResult> MakeCall(string to)
    {
        if (State is not PhoneState.Connected)
            throw new InvalidPhoneStateException();

        if (CallState is not CallState.Idle)
            throw new InvalidCallStateException();

        InCallWith = to;
        CallState = CallState.Dialing;

        CallResult result = await ConnectedBaseStation!.InitiateCall(this, to);

        if (result is not CallResult.Established)
        {
            InCallWith = null;
            CallState = CallState.Idle;

            return result;
        }

        CallState = CallState.InCall;

        return result;
    }

    public virtual Task<CallAnswer> ReceiveCall(string from)
    {
        if (State is not PhoneState.Connected)
            throw new InvalidPhoneStateException();

        if (CallState is not CallState.Idle)
            throw new InvalidCallStateException();

        InCallWith = from;
        CallState = CallState.AwaitingAnswer;

        TaskCompletionSource<CallAnswer> callAnswerCompletionSource = CallAnswerCompletionSource =
            new TaskCompletionSource<CallAnswer>(TaskCreationOptions.RunContinuationsAsynchronously);

        CallReceived?.Invoke(this, new CallEventArgs(from, Number));

        return callAnswerCompletionSource.Task;
    }

    public virtual void AnswerCall(CallAnswer answer)
    {
        if (State is not PhoneState.Connected)
            throw new InvalidPhoneStateException();

        if (CallState is not CallState.AwaitingAnswer)
            throw new InvalidCallStateException();

        CallAnswerCompletionSource!.SetResult(answer);

        CallAnswerCompletionSource = null;

        if (answer is CallAnswer.Agreed)
        {
            CallState = CallState.InCall;
            return;
        }

        CallState = CallState.Idle;
        InCallWith = null;
    }

    public virtual void EndCall()
    {
        if (State is not PhoneState.Connected)
            throw new InvalidPhoneStateException();

        if (CallState is CallState.Idle)
            throw new InvalidCallStateException();

        CallAnswerCompletionSource?.SetCanceled();
        CallAnswerCompletionSource = null;

        CallEnded?.Invoke(this, new CallEventArgs(Number, InCallWith!));

        InCallWith = null;
        CallState = CallState.Idle;
    }

    protected virtual BaseStation? FindBaseStation()
    {
        BaseStation? nearestStation =
            BaseStation.AllEnabledStations
                .Where(IsCoveredBy)
                .MinBy(x => x.Location.CalculateKmDistanceTo(Location));

        return nearestStation;
    }

    protected bool IsCoveredBy(BaseStation baseStation) =>
        baseStation.Location.CalculateKmDistanceTo(Location) <= baseStation.CoverageRadiusKm;

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
