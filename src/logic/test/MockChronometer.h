#ifndef LOGIC_TEST_MOCK_CHRONOMETER_H
#define LOGIC_TEST_MOCK_CHRONOMETER_H

#include "logic/IChronometer.h"
#include <gmock/gmock.h>

class MockChronometer : public IChronometer
{
    public:
        MOCK_METHOD0(restart, void());
        MOCK_CONST_METHOD0(count, TimeQuantity());
};

#endif

