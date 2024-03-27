namespace TelecommsSimulation.Engine;

public interface ITimeAwareSimulatable : ISimulatable
{
    public void ProcessTimeTick(ulong currentTick);
}
