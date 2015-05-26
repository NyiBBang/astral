#ifndef LOGIC_TEST_MOCK_LOOP_STOPPER_H
#define LOGIC_TEST_MOCK_LOOP_STOPPER_H

#include "logic/ILoopStopper.h"
#include <gmock/gmock.h>

class MockLoopStopper : public ILoopStopper
{
    public:
        MOCK_CONST_METHOD0(shouldStop, bool());
};

#endif

