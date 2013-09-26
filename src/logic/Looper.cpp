#include "Looper.h"
#include "IStepper.h"
#include "ILoopStopper.h"

Looper::Looper(IStepper& stepper, const ILoopStopper& stopper)
    : stepper_(stepper)
    , stopper_(stopper)
{}

void Looper::run()
{
    while (!stopper_.shouldStop())
    {
        stepper_.step();
    }
}

