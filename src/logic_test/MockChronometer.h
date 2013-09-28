#ifndef LOGIC_TEST_MOCK_CHRONOMETER_H
#define LOGIC_TEST_MOCK_CHRONOMETER_H

#include "config.h"
#include "logic/IChronometer.h"

MOCK_BASE_CLASS(MockChronometer, IChronometer)
{
    MOCK_METHOD(restart, 0);
    MOCK_METHOD(count, 0);
};

#endif


