#include "logic/StepDispenser.h"
#include "MockStepper.h"
#include <gtest/gtest.h>

using boost::units::si::seconds;

TEST(LogicTest, Dispenser_notifies_suscribed_steppers_with_same_duration)
{
    MockStepper stepper1;
    MockStepper stepper2;
    StepDispenser dispenser;
    dispenser.suscribe(stepper1);
    dispenser.suscribe(stepper2);
    EXPECT_CALL(stepper1, step(TimeQuantity(51 * seconds)));
    EXPECT_CALL(stepper2, step(TimeQuantity(51 * seconds)));
    dispenser.step(51 * seconds);
}

TEST(LogicTest, Dispenser_wont_notify_an_unsuscribed_stepper)
{
    MockStepper stepper;
    StepDispenser dispenser;
    dispenser.suscribe(stepper);
    EXPECT_CALL(stepper, step(TimeQuantity(62 * seconds)));
    dispenser.step(62 * seconds);
    ::testing::Mock::VerifyAndClearExpectations(&stepper);
    dispenser.unsuscribe(stepper);
    dispenser.step(1337 * seconds);
}

