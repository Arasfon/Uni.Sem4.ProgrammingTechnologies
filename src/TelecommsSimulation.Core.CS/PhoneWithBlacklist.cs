using System.Threading.Tasks;

using TelecommsSimulation.Utilities;

namespace TelecommsSimulation.Core;

public class PhoneWithBlacklist : Phone
{
    public ConcurrentHashSet<string> Blacklist { get; }

    public PhoneWithBlacklist(string number, Coordinates location, double batteryLevel = 100) : base(number, location, batteryLevel) =>
        Blacklist = new ConcurrentHashSet<string>();

    public PhoneWithBlacklist(string number, Coordinates location, ConcurrentHashSet<string> blacklist, double batteryLevel = 100) : base(
        number, location, batteryLevel) =>
        Blacklist = blacklist;

    public override Task<CallAnswer> ReceiveCall(string from)
    {
        if (State is not PhoneState.Connected)
            throw new InvalidPhoneStateException();

        if (CallState is not CallState.Idle)
            throw new InvalidCallStateException();

        return Blacklist.Contains(from) ? Task.FromResult(CallAnswer.Declined) : base.ReceiveCall(from);
    }
}
