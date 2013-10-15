#include "config.h"
#include "logic/Chronometer.h"
#include <thread>

BOOST_AUTO_TEST_CASE(Chronometer_returns_zero_as_long_as_not_restarted)
{
    Chronometer chrono;
    BOOST_CHECK_EQUAL(chrono.count(), 0 * seconds);
}

BOOST_AUTO_TEST_CASE(Chronometer_returns_time_passed_since_last_restart_with_high_precision)
{
    Chronometer chrono;
    chrono.restart();
    const int sleepdura = 1;
    std::this_thread::sleep_for(std::chrono::seconds(sleepdura));
    BOOST_CHECK_CLOSE(chrono.count().value(), static_cast<double>(sleepdura), 0.00001);
}

BOOST_AUTO_TEST_CASE(Chronometer_restart_effectively_resets_count_to_zero)
{
    Chronometer chrono;
    chrono.restart();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    chrono.restart();
    const int sleepdura = 1;
    std::this_thread::sleep_for(std::chrono::seconds(sleepdura));
    BOOST_CHECK_CLOSE(chrono.count().value(), static_cast<double>(sleepdura), 0.00001);
}

