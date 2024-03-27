using System.Collections.Generic;
using System.ComponentModel;

namespace TelecommsSimulation.Engine;

public interface ISimulationEngine<T> : INotifyPropertyChanged
    where T : ISimulatable
{
    IEnumerable<T> SimulatedEntities { get; }

    public bool IsRunning { get; }

    public void Start();
    public void Stop();

    public void Add(T simulatable);
    public void Remove(T simulatable);
}
