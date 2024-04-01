#pragma once

namespace TelecommsSimulation
{
    generic<typename T> where T : Core::ILocatableMovable
    public ref class RandomlyMovingSimulatable : public Engine::ITimeAwareSimulatable,
                                                 public Engine::IWrapperSimulatable<T>
    {
        initonly T _entity;
        initonly System::Random^ _random = gcnew System::Random();

    public:
        property T Entity
        {
            virtual T get();
        }

        RandomlyMovingSimulatable(T entity);

        virtual void ProcessTimeTick(unsigned long long currentTick);
        virtual void Start() {}
        virtual void Stop() {}
    };
}
