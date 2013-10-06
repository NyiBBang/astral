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
        const auto elapsed = chrono_.count();
        chrono_.restart();
        stepper_.step(elapsed);
    }
}

