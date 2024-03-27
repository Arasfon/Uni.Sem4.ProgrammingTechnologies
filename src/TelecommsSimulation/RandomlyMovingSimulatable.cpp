#include "pch.h"

#include "RandomlyMovingSimulatable.h"

using namespace TelecommsSimulation::Core;

namespace TelecommsSimulation
{
    generic<typename T>
    T RandomlyMovingSimulatable<T>::Entity::get()
    {
        return _entity;
    }

    generic<typename T>
    RandomlyMovingSimulatable<T>::RandomlyMovingSimulatable(T entity)
    {
        _entity = entity;
    }

    generic<typename T>
    void RandomlyMovingSimulatable<T>::ProcessTimeTick(unsigned long long currentTick)
    {
        _entity->Location = Coordinates(_random->NextDouble(), _random->NextDouble());
    }
}
