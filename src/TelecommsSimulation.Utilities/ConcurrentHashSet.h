#pragma once

namespace TelecommsSimulation::Utilities
{
    generic<typename T>
    public ref class ConcurrentHashSet : public System::Collections::Generic::IEnumerable<T>,
                                         public System::Collections::Specialized::INotifyCollectionChanged
    {
        initonly System::Collections::Concurrent::ConcurrentDictionary<T, System::Byte>^ _internalDictionary =
            gcnew System::Collections::Concurrent::ConcurrentDictionary<T, System::Byte>();

    public:
        virtual System::Collections::Generic::IEnumerator<T>^ GetEnumerator() = System::Collections::Generic::IEnumerable<T>::GetEnumerator;
        virtual System::Collections::IEnumerator^ GetEnumeratorNonGeneric() = System::Collections::IEnumerable::GetEnumerator;

        bool TryAdd(T value);
        bool TryRemove(T value);
        bool Contains(T value);
        void Clear();

        virtual event System::Collections::Specialized::NotifyCollectionChangedEventHandler^ CollectionChanged;
    };
}
