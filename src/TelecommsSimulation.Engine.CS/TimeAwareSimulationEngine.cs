using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Timers;

using TelecommsSimulation.Utilities;

using Timer = System.Timers.Timer;

namespace TelecommsSimulation.Engine;

public class TimeAwareSimulationEngine<T> : ISimulationEngine<T>
    where T : ITimeAwareSimulatable
{
    public const double BaseTickIntervalMilliseconds = 100;

    private double _speed = 1;

    public double Speed
    {
        get => _speed;
        set
        {
            value = MathExtensions.Clamp(value, 0.01, 2);

            SetField(ref _speed, value);
            OnPropertyChanged(nameof(TickIntervalMilliseconds));
            OnPropertyChanged(nameof(TickInterval));

            Timer.Interval = TickIntervalMilliseconds;
        }
    }

    // Workaround for TrackBar
    public int SpeedPercentage
    {
        get => (int)(Speed * 100);
        set => Speed = value / 100.0;
    }

    public double TickIntervalMilliseconds => BaseTickIntervalMilliseconds / Speed;

    public TimeSpan TickInterval => TimeSpan.FromMilliseconds(TickIntervalMilliseconds);

    public ulong CurrentTick
    {
        get => _currentTick;
        private set => SetField(ref _currentTick, value);
    }

    private readonly ConcurrentHashSet<T> _simulatedEntities = [];

    // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
    public IEnumerable<T> SimulatedEntities => _simulatedEntities.ToImmutableArray();

    private bool _isRunning;

    public bool IsRunning
    {
        get => _isRunning;
        private set => SetField(ref _isRunning, value);
    }

    protected readonly Timer Timer;
    private ulong _currentTick;

    public TimeAwareSimulationEngine()
    {
        Timer = new Timer { Interval = TickIntervalMilliseconds };

        Timer.Elapsed += OnTimeTick;
    }

    public void Start()
    {
        if (IsRunning)
            throw new InvalidSimulationStateException();

        Timer.Start();

        IsRunning = true;
    }

    public void Stop()
    {
        if (!IsRunning)
            throw new InvalidSimulationStateException();

        Timer.Stop();

        CurrentTick = 0;

        IsRunning = false;
    }

    public void Add(T simulatable) =>
        _simulatedEntities.TryAdd(simulatable);

    public void Remove(T simulatable) =>
        _simulatedEntities.TryRemove(simulatable);

    protected virtual void OnTimeTick(object sender, ElapsedEventArgs e)
    {
        if (!IsRunning)
            return;

        CurrentTick++;

        foreach (T entity in _simulatedEntities)
            entity.ProcessTimeTick(CurrentTick);
    }

    public virtual event PropertyChangedEventHandler? PropertyChanged;

    protected virtual void OnPropertyChanged([CallerMemberName] string? propertyName = null) =>
        PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));

    protected bool SetField<TValue>(ref TValue field, TValue value, [CallerMemberName] string? propertyName = null)
    {
        if (EqualityComparer<TValue>.Default.Equals(field, value))
            return false;

        field = value;

        OnPropertyChanged(propertyName);

        return true;
    }
}
