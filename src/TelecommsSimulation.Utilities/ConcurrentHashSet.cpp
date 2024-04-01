#include "pch.h"

#include "ConcurrentHashSet.h"

#include "CollectionExtensions.h"

using namespace System;
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
    Collections::IEnumerator^ ConcurrentHashSet<T>::GetEnumeratorNonGeneric()
    {
        return GetEnumerator();
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::TryAdd(T item)
    {
        const bool result = _internalDictionary->TryAdd(item, 0);

        if (result)
            CollectionChanged(this, gcnew NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction::Add, item));

        return result;
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::TryRemove(T item)
    {
        Byte discard;
        const bool result = CollectionExtensions::Remove(_internalDictionary, item, discard);

        if (result)
            CollectionChanged(
                this, gcnew NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction::Remove, item));

        return result;
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::Contains(T item)
    {
        return _internalDictionary->ContainsKey(item);
    }

    generic<typename T>
    void ConcurrentHashSet<T>::Clear()
    {
        _internalDictionary->Clear();
        CollectionChanged(this, gcnew NotifyCollectionChangedEventArgs(NotifyCollectionChangedAction::Reset));
    }

    generic<typename T>
    void ConcurrentHashSet<T>::Add(T item)
    {
        if (!TryAdd(item))
        {
            throw gcnew ArgumentException("Item already exists", "item");
        }
    }

    generic<typename T>
    void ConcurrentHashSet<T>::CopyTo(array<T>^ array, const int arrayIndex)
    {
        _internalDictionary->Keys->CopyTo(array, arrayIndex);
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::Remove(T item)
    {
        return TryRemove(item);
    }

    generic<typename T>
    int ConcurrentHashSet<T>::Count::get()
    {
        return _internalDictionary->Count;
    }

    generic<typename T>
    bool ConcurrentHashSet<T>::IsReadOnly::get()
    {
        return false;
    }
}
