#ifndef LOGIC_TEST_MOCK_STEPPER_H
#define LOGIC_TEST_MOCK_STEPPER_H

#include "logic/IStepper.h"
#include <gmock/gmock.h>

class MockStepper : public IStepper
{
    public:
        MOCK_METHOD1(step, void(TimeQuantity));
};

#endif

