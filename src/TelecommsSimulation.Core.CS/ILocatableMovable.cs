namespace TelecommsSimulation.Core;

public interface ILocatableMovable : ILocatable
{
    public new Coordinates Location { get; set; }
}
