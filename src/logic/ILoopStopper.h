#ifndef LOGIC_I_LOOP_STOPPER_H
#define LOGIC_I_LOOP_STOPPER_H

class ILoopStopper
{
    public:
        ILoopStopper() {}
        virtual ~ILoopStopper() {}
        virtual bool shouldStop() const = 0;
};

#endif

