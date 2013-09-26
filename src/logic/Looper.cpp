#include "Looper.h"
#include "IStepper.h"
#include "ILoopStopper.h"
#include <chrono>

Looper::Looper(IStepper& stepper, const ILoopStopper& stopper)
    : stepper_(stepper)
    , stopper_(stopper)
{}

void Looper::run()
{
    auto lastStep = std::chrono::high_resolution_clock::now();
    while (!stopper_.shouldStop())
    {
        using namespace std::chrono;
        const auto duration =
            duration_cast<milliseconds>(steady_clock::now() - lastStep);
        stepper_.step(duration.count());
    }
}

