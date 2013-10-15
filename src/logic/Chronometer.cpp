#include "Chronometer.h"

using namespace std::chrono;

Chronometer::Chronometer()
{}

void Chronometer::restart()
{
    last_ = system_clock::now();
}

quantity<si::time, double> Chronometer::count() const
{
    if (last_.time_since_epoch().count() == 0) return 0;
    const auto elapsed = duration_cast<milliseconds>(system_clock::now() - last_);
    return quantity<si::time, double>(elapsed.count() * milli * si::seconds);
}

