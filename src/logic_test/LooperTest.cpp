#include "config.h"
#include "logic/Looper.h"
#include "MockStepper.h"
#include "MockLoopStopper.h"

BOOST_AUTO_TEST_CASE(Looper_steps_until_stopped)
{
    MockStepper stepper;
    MockLoopStopper stopper;
    Looper looper(stepper, stopper);
    MOCK_EXPECT(stepper.step).exactly(3);
    mock::sequence s;
    MOCK_EXPECT(stopper.shouldStop).in(s).exactly(3).returns(false);
    MOCK_EXPECT(stopper.shouldStop).in(s).once().returns(true);
    looper.run();
}

