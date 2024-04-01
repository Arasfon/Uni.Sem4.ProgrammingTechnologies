#include "pch.h"

#include "VisualizationRegistry.h"

namespace TelecommsSimulation
{
    generic<typename T>
    VisualizationRegistry<T>::VisualizationRegistry()
    {
        _internalHashSet = gcnew Utilities::ConcurrentHashSet<T>();
    }

    generic<typename T>
    int VisualizationRegistry<T>::Count::get()
    {
        return _internalHashSet->Count;
    }

    generic<typename T>
    bool VisualizationRegistry<T>::IsReadOnly::get()
    {
        return false;
    }

    generic<typename T>
    System::Collections::Generic::IEnumerator<T>^ VisualizationRegistry<T>::GetEnumerator()
    {
        return _internalHashSet->GetEnumerator();
    }

    generic<typename T>
    System::Collections::IEnumerator^ VisualizationRegistry<T>::GetEnumeratorNonGeneric()
    {
        return _internalHashSet->GetEnumeratorNonGeneric();
    }

    generic<typename T>
    bool VisualizationRegistry<T>::TryAdd(T item)
    {
        return _internalHashSet->TryAdd(item);
    }

    generic<typename T>
    bool VisualizationRegistry<T>::TryRemove(T item)
    {
        return _internalHashSet->TryRemove(item);
    }

    generic<typename T>
    bool VisualizationRegistry<T>::Contains(T item)
    {
        return _internalHashSet->Contains(item);
    }

    generic<typename T>
    void VisualizationRegistry<T>::Clear()
    {
        _internalHashSet->Clear();
    }

    generic<typename T>
    void VisualizationRegistry<T>::Add(T item)
    {
        _internalHashSet->Add(item);
    }

    generic<typename T>
    bool VisualizationRegistry<T>::Remove(T item)
    {
        return _internalHashSet->Remove(item);
    }

    generic<typename T>
    void VisualizationRegistry<T>::CopyTo(array<T>^ array, const int arrayIndex)
    {
        _internalHashSet->CopyTo(array, arrayIndex);
    }
}
