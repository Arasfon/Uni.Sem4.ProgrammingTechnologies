using System;

namespace TelecommsSimulation.Core;

public class CallEventArgs : EventArgs
{
    public string CallerNumber { get; }
    public string ReceiverNumber { get; }

    public CallEventArgs(string callerNumber, string receiverNumber)
    {
        CallerNumber = callerNumber;
        ReceiverNumber = receiverNumber;
    }
}
