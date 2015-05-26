#ifndef LOGIC_I_STEPPER_H
#define LOGIC_I_STEPPER_H

#include "Units.h"

class IStepper
{
    public:
        IStepper() {}
        virtual ~IStepper() {}
        virtual void step(TimeQuantity elapsed) = 0;
};

#endif

