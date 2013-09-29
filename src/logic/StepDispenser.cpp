#include "StepDispenser.h"
#include <algorithm>

void StepDispenser::suscribe(IStepper& stepper)
{
    steppers_.push_back(&stepper);
}

void StepDispenser::unsuscribe(IStepper& stepper)
{
    steppers_.erase(std::remove(steppers_.begin(), steppers_.end(), &stepper),
                    steppers_.end());
}

void StepDispenser::step(long microseconds)
{
    for (IStepper* const stepper : steppers_)
        stepper->step(microseconds);
}

