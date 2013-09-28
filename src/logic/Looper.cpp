#include "Looper.h"
#include "IStepper.h"
#include "ILoopStopper.h"
#include "IChronometer.h"
#include <chrono>

Looper::Looper(IStepper& stepper, const ILoopStopper& stopper, IChronometer& chrono)
    : stepper_(stepper)
    , stopper_(stopper)
    , chrono_(chrono)
{}

void Looper::run()
{
    while (!stopper_.shouldStop())
    {
        stepper_.step(chrono_.count());
        chrono_.restart();
    }
}

