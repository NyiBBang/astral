#ifndef LOGIC_STEP_DISPENSER_H
#define LOGIC_STEP_DISPENSER_H

#include "IStepper.h"
#include "IStepperRegistrar.h"
#include <vector>

class StepDispenser final : public IStepper
                          , public IStepperRegistrar
{
    public:
        virtual void suscribe(IStepper& stepper) override;
        virtual void unsuscribe(IStepper& stepper) override;
        virtual void step(quantity<si::time, double> elapsed) override;

    private:
        std::vector<IStepper*> steppers_;
};

#endif

