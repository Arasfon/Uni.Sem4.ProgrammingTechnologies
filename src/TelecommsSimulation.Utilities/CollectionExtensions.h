#pragma once

namespace TelecommsSimulation::Utilities
{
    [System::Runtime::CompilerServices::ExtensionAttribute]
    public ref class CollectionExtensions sealed
    {
    public:
        generic<typename TKey, typename TValue>
        [System::Runtime::CompilerServices::ExtensionAttribute]
        static bool Remove(System::Collections::Generic::IDictionary<TKey, TValue>^ dictionary, TKey key,
                           [System::Runtime::InteropServices::Out] TValue% value);
    };
}
