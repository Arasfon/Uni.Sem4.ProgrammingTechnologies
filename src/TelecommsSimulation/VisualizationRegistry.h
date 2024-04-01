#pragma once

#include "IVisualizationRegistry.h"

namespace TelecommsSimulation
{
    generic<typename T>
    public ref class VisualizationRegistry : public IVisualizationRegistry<T>
    {
        // Workaround (see constructor): C++/CLI does not want to work with default member initializers sometimes without a reason (just does not create it)
        initonly Utilities::ConcurrentHashSet<T>^ _internalHashSet; /*= gcnew Utilities::ConcurrentHashSet<T>();*/

    public:
        VisualizationRegistry();

        property int Count { virtual int get(); }
        property bool IsReadOnly { virtual bool get(); }

        virtual System::Collections::Generic::IEnumerator<T>^ GetEnumerator() =
        System::Collections::Generic::IEnumerable<T>::GetEnumerator;
        virtual System::Collections::IEnumerator^ GetEnumeratorNonGeneric() =
        System::Collections::IEnumerable::GetEnumerator;

        virtual bool TryAdd(T item);
        virtual bool TryRemove(T item);
        virtual bool Contains(T item);
        virtual void Clear();

        virtual void Add(T item) = System::Collections::Generic::ICollection<T>::Add;
        virtual bool Remove(T item) = System::Collections::Generic::ICollection<T>::Remove;
        virtual void CopyTo(array<T>^ array, int arrayIndex);
    };
}
