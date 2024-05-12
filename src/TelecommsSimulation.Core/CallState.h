#pragma once

namespace TelecommsSimulation::Core
{
    public enum class CallState
    {
        Idle,
        Dialing,
        AwaitingAnswer,
        InCall
    };
}