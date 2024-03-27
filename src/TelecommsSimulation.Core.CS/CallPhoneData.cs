namespace TelecommsSimulation.Core;

public class CallPhoneData
{
    public Phone Caller { get; }
    public Phone Receiver { get; }

    public CallPhoneData(Phone caller, Phone receiver)
    {
        Caller = caller;
        Receiver = receiver;
    }
}
