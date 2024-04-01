#pragma once

namespace TelecommsSimulation::Utilities
{
    generic<typename T>
    public ref class ConcurrentHashSet : public System::Collections::Generic::IEnumerable<T>,
                                         public System::Collections::Specialized::INotifyCollectionChanged,
                                         public System::Collections::Generic::ICollection<T>
    {
        initonly System::Collections::Concurrent::ConcurrentDictionary<T, System::Byte>^ _internalDictionary =
            gcnew System::Collections::Concurrent::ConcurrentDictionary<T, System::Byte>();

    public:
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

        virtual event System::Collections::Specialized::NotifyCollectionChangedEventHandler^ CollectionChanged;
    };
}
