#ifndef LOGIC_LOOPER_H
#define LOGIC_LOOPER_H

class IStepper;
class ILoopStopper;

class Looper final
{
    public:
        Looper(IStepper& stepper, const ILoopStopper& stopper);
        void run();
        void stop();

    private:
        IStepper& stepper_;
        const ILoopStopper& stopper_;
};

#endif

