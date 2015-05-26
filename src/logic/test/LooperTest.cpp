#include "logic/Looper.h"
#include "MockStepper.h"
#include "MockLoopStopper.h"
#include "MockChronometer.h"
#include <gtest/gtest.h>

TEST(LogicTest, Looper_steps_until_stopped)
{
    MockStepper stepper;
    MockLoopStopper stopper;
    MockChronometer chrono;
    Looper looper(stepper, stopper, chrono);
    ::testing::Sequence s;
    EXPECT_CALL(stopper, shouldStop()).InSequence(s).WillOnce(::testing::Return(false));
    EXPECT_CALL(chrono, count()).InSequence(s).WillOnce(::testing::Return(42 * si::seconds));
    EXPECT_CALL(chrono, restart()).InSequence(s);
    EXPECT_CALL(stepper, step(TimeQuantity(42 * si::seconds))).InSequence(s);
    EXPECT_CALL(stopper, shouldStop()).InSequence(s).WillOnce(::testing::Return(true));
    looper.run();
}

