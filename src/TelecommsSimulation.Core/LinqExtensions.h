#pragma once

namespace TelecommsSimulation::Core
{
    [System::Runtime::CompilerServices::ExtensionAttribute]
    public ref class LinqExtensions sealed
    {
    public:
        generic<typename TSource, typename TKey>
        [System::Runtime::CompilerServices::ExtensionAttribute]
        static TSource MinBy(System::Collections::Generic::IEnumerable<TSource>^ source,
                             System::Func<TSource, TKey>^ keySelector);

        generic<typename TSource, typename TKey>
        [System::Runtime::CompilerServices::ExtensionAttribute]
        static TSource MinBy(System::Collections::Generic::IEnumerable<TSource>^ source,
                             System::Func<TSource, TKey>^ keySelector,
                             System::Collections::Generic::IComparer<TKey>^ comparer);
    };
}
