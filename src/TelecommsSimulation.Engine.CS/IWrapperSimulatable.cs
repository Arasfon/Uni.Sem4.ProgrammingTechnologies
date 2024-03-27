namespace TelecommsSimulation.Engine;

public interface IWrapperSimulatable<out T> : ISimulatable
{
    public T Entity { get; }
}
