﻿using System;
using System.Collections.Generic;

namespace TelecommsSimulation.Core;

public static class LinqExtensions
{
    public static TSource? MinBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector) =>
        MinBy(source, keySelector, null);

    public static TSource? MinBy<TSource, TKey>(this IEnumerable<TSource> source, Func<TSource, TKey> keySelector,
        IComparer<TKey>? comparer)
    {
        if (source == null)
            throw new ArgumentNullException();

        if (keySelector == null)
            throw new ArgumentNullException();

        comparer ??= Comparer<TKey>.Default;

        using IEnumerator<TSource> e = source.GetEnumerator();

        if (!e.MoveNext())
        {
            if (default(TSource) is null)
                return default;
            throw new Exception();
        }

        TSource value = e.Current;
        TKey key = keySelector(value);

        if (default(TKey) is null)
        {
            if (key == null)
            {
                TSource firstValue = value;

                do
                {
                    if (!e.MoveNext())
                    {
                        // All keys are null, surface the first element.
                        return firstValue;
                    }

                    value = e.Current;
                    key = keySelector(value);
                } while (key == null);
            }

            while (e.MoveNext())
            {
                TSource nextValue = e.Current;
                TKey nextKey = keySelector(nextValue);
                if (nextKey != null && comparer.Compare(nextKey, key) < 0)
                {
                    key = nextKey;
                    value = nextValue;
                }
            }
        }
        else
        {
            // ReSharper disable once PossibleUnintendedReferenceComparison
            if (comparer == Comparer<TKey>.Default)
            {
                while (e.MoveNext())
                {
                    TSource nextValue = e.Current;
                    TKey nextKey = keySelector(nextValue);
                    if (Comparer<TKey>.Default.Compare(nextKey, key) < 0)
                    {
                        key = nextKey;
                        value = nextValue;
                    }
                }
            }
            else
            {
                while (e.MoveNext())
                {
                    TSource nextValue = e.Current;
                    TKey nextKey = keySelector(nextValue);
                    if (comparer.Compare(nextKey, key) < 0)
                    {
                        key = nextKey;
                        value = nextValue;
                    }
                }
            }
        }

        return value;
    }
}
