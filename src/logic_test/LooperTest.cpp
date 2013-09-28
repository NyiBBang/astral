#include "config.h"
#include "logic/Looper.h"
#include "MockStepper.h"
#include "MockLoopStopper.h"
#include "MockChronometer.h"

BOOST_AUTO_TEST_CASE(Looper_steps_until_stopped)
{
    MockStepper stepper;
    MockLoopStopper stopper;
    MockChronometer chrono;
    Looper looper(stepper, stopper, chrono);
    mock::sequence s;
    MOCK_EXPECT(stopper.shouldStop).once().in(s).returns(false);
    MOCK_EXPECT(chrono.count).once().in(s).returns(42);
    MOCK_EXPECT(stepper.step).once().in(s).with(42);
    MOCK_EXPECT(chrono.restart).once().in(s);
    MOCK_EXPECT(stopper.shouldStop).once().in(s).returns(true);
    looper.run();
}

