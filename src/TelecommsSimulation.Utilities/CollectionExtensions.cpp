#include "pch.h"

namespace TelecommsSimulation::Utilities
{
    generic<typename TKey, typename TValue>
    bool CollectionExtensions::Remove(System::Collections::Generic::IDictionary<TKey, TValue>^ dictionary, TKey key,
                                      TValue% value)
    {
        if (dictionary->TryGetValue(key, value))
        {
            dictionary->Remove(key);
            return true;
        }

        return false;
    }
}
