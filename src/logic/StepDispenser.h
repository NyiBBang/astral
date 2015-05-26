#ifndef LOGIC_STEP_DISPENSER_H
#define LOGIC_STEP_DISPENSER_H

#include "IStepper.h"
#include "IStepperRegistrar.h"
#include <vector>

class StepDispenser final : public IStepper
                          , public IStepperRegistrar
{
    public:
        void suscribe(IStepper& stepper) override;
        void unsuscribe(IStepper& stepper) override;
        void step(TimeQuantity elapsed) override;

    private:
        std::vector<IStepper*> steppers_;
};

#endif

