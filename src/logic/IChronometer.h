#ifndef LOGIC_CHRONOMETER_H
#define LOGIC_CHRONOMETER_H

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using boost::units::quantity;
using namespace boost::units;

class IChronometer
{
    public:
        IChronometer() {}
        virtual ~IChronometer() {}
        virtual void restart() = 0;
        virtual quantity<si::time, double> count() const = 0;
};

#endif

