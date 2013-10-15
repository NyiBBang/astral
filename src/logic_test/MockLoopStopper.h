#ifndef LOGIC_TEST_MOCK_LOOP_STOPPER_H
#define LOGIC_TEST_MOCK_LOOP_STOPPER_H

#include "config.h"
#include "logic/ILoopStopper.h"

MOCK_BASE_CLASS(MockLoopStopper, ILoopStopper)
{
    MOCK_METHOD(shouldStop, 0);
};

#endif

