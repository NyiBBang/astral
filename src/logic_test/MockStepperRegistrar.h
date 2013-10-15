#ifndef LOGIC_TEST_MOCK_STEPPER_REGISTRAR_H
#define LOGIC_TEST_MOCK_STEPPER_REGISTRAR_H

#include "config.h"
#include "logic/IStepperRegistrar.h"

MOCK_BASE_CLASS(MockStepperRegistrar, IStepperRegistrar)
{
    MOCK_METHOD(suscribe, 1);
    MOCK_METHOD(unsuscribe, 1);
};

#endif

