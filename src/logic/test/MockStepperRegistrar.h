#ifndef LOGIC_TEST_MOCK_STEPPER_REGISTRAR_H
#define LOGIC_TEST_MOCK_STEPPER_REGISTRAR_H

#include "logic/IStepperRegistrar.h"
#include <gmock/gmock.h>

class MockStepperRegistrar : public IStepperRegistrar
{
    public:
        MOCK_METHOD1(suscribe, void(IStepper&));
        MOCK_METHOD1(unsuscribe, void(IStepper&));
};

#endif

