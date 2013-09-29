#include "config.h"
#include "logic/StepDispenser.h"
#include "MockStepper.h"

BOOST_AUTO_TEST_CASE(Dispenser_notifies_suscribed_steppers_with_same_duration)
{
    MockStepper stepper1;
    MockStepper stepper2;
    StepDispenser dispenser;
    dispenser.suscribe(stepper1);
    dispenser.suscribe(stepper2);
    MOCK_EXPECT(stepper1.step).once().with(51);
    MOCK_EXPECT(stepper2.step).once().with(51);
    dispenser.step(51);
}

BOOST_AUTO_TEST_CASE(Dispenser_wont_notify_an_unsuscribed_stepper)
{
    MockStepper stepper;
    StepDispenser dispenser;
    dispenser.suscribe(stepper);
    MOCK_EXPECT(stepper.step).once().with(62);
    dispenser.step(62);
    mock::verify();
    dispenser.unsuscribe(stepper);
    dispenser.step(1337);
}

