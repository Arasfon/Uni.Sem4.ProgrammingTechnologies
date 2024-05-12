#include "pch.h"

#include "LinqExtensions.h"

using namespace System;
using namespace System::Collections::Generic;

namespace TelecommsSimulation::Core
{
    generic<typename TSource, typename TKey>
    TSource LinqExtensions::MinBy(IEnumerable<TSource>^ source, Func<TSource, TKey>^ keySelector)
    {
        return MinBy(source, keySelector, safe_cast<IComparer<TKey>^>(nullptr));
    }

    generic<typename TSource, typename TKey>
    TSource LinqExtensions::MinBy(IEnumerable<TSource>^ source, Func<TSource, TKey>^ keySelector, IComparer<TKey>^ comparer)
    {
        if (source == nullptr)
            throw gcnew ArgumentNullException();

        if (keySelector == nullptr)
            throw gcnew ArgumentNullException();

        if (comparer == nullptr)
            comparer = Comparer<TKey>::Default;

        IEnumerator<TSource>^ e = source->GetEnumerator();

        try
        {
            if (!e->MoveNext())
            {
                if (TSource() == nullptr) // Check for reference types
                    return TSource();
                throw gcnew Exception();
            }

            TSource value = e->Current;
            TKey key = keySelector(value);

            if (TKey() == nullptr) // Handling null keys if TKey is a reference type
            {
                if (key == nullptr)
                {
                    TSource firstValue = value;

                    do
                    {
                        if (!e->MoveNext())
                        {
                            // All keys are null, surface the first element.
                            return firstValue;
                        }

                        value = e->Current;
                        key = keySelector(value);
                    } while (key == nullptr);
                }

                while (e->MoveNext())
                {
                    TSource nextValue = e->Current;
                    TKey nextKey = keySelector(nextValue);
                    if (nextKey != nullptr && comparer->Compare(nextKey, key) < 0)
                    {
                        key = nextKey;
                        value = nextValue;
                    }
                }
            }
            else
            {
                // When TKey is a value type or TKey has a proper comparer
                if (comparer == Comparer<TKey>::Default)
                {
                    while (e->MoveNext())
                    {
                        TSource nextValue = e->Current;
                        TKey nextKey = keySelector(nextValue);
                        if (Comparer<TKey>::Default->Compare(nextKey, key) < 0)
                        {
                            key = nextKey;
                            value = nextValue;
                        }
                    }
                }
                else
                {
                    while (e->MoveNext())
                    {
                        TSource nextValue = e->Current;
                        TKey nextKey = keySelector(nextValue);
                        if (comparer->Compare(nextKey, key) < 0)
                        {
                            key = nextKey;
                            value = nextValue;
                        }
                    }
                }
            }

            return value;
        }
        finally
        {
            delete e;
        }
    }
}
