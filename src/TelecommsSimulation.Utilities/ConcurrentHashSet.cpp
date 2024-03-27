#include "pch.h"

#include "ConcurrentHashSet.h"

#include "CollectionExtensions.h"

using namespace System::Collections::Generic;
using namespace System::Collections::Specialized;

namespace TelecommsSimulation::Utilities
{
    generic<typename T>
    IEnumerator<T>^ ConcurrentHashSet<T>::GetEnumerator()
    {
        return _internalDictionary->Keys->GetEnumerator();
    }

    generic<typename T>
    System::Collections::IEnumerator^ ConcurrentHashSet<T>::GetEnumeratorNonGeneric()
    {
        return GetEnumerator();
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::TryAdd(T value)
    {
        const bool result = _internalDictionary->TryAdd(value, 0);

        if (result)
            CollectionChanged(this, gcnew NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction::Add, value));

        return result;
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::TryRemove(T value)
    {
        System::Byte discard;
        bool result = CollectionExtensions::Remove(_internalDictionary, value, discard);

        if (result)
            CollectionChanged(
                this, gcnew NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction::Remove, value));

        return result;
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::Contains(T value)
    {
        return _internalDictionary->ContainsKey(value);
    }

    generic<typename T>
    void ConcurrentHashSet<T>::Clear()
    {
        _internalDictionary->Clear();
    }
}
