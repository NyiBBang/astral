#ifndef LOGIC_STEP_DISPENSER_H
#define LOGIC_STEP_DISPENSER_H

#include "IStepper.h"
#include <vector>

class StepDispenser final : public IStepper
{
    public:
        void suscribe(IStepper& stepper);
        void unsuscribe(IStepper& stepper);
        virtual void step(quantity<si::time, double> elapsed) override;

    private:
        std::vector<IStepper*> steppers_;
};

#endif

