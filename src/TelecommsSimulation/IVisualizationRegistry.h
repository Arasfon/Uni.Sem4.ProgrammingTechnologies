#pragma once

namespace TelecommsSimulation
{
    generic<typename T>
    public interface class IVisualizationRegistry : System::Collections::Generic::ICollection<T>
    {
        virtual bool TryAdd(T item);
        virtual bool TryRemove(T item);
    };
}
