#include "logic/Chronometer.h"
#include <gtest/gtest.h>
#include <thread>

TEST(LogicTest, Chronometer_returns_zero_as_long_as_not_restarted)
{
    Chronometer chrono;
    EXPECT_EQ(chrono.count(), 0 * seconds);
}

TEST(LogicTest, Chronometer_returns_time_passed_since_last_restart_with_high_precision)
{
    Chronometer chrono;
    chrono.restart();
    const int sleepdura = 1;
    std::this_thread::sleep_for(std::chrono::seconds(sleepdura));
    EXPECT_DOUBLE_EQ(chrono.count().value(), static_cast<double>(sleepdura));
}

TEST(LogicTest, Chronometer_restart_effectively_resets_count_to_zero)
{
    Chronometer chrono;
    chrono.restart();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    chrono.restart();
    const int sleepdura = 1;
    std::this_thread::sleep_for(std::chrono::seconds(sleepdura));
    EXPECT_DOUBLE_EQ(chrono.count().value(), static_cast<double>(sleepdura));
}

