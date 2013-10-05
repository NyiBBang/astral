#ifndef LOGIC_I_STEPPER_H
#define LOGIC_I_STEPPER_H

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using boost::units::quantity;
using namespace boost::units;

class IStepper
{
    public:
        IStepper() {}
        virtual ~IStepper() {}
        virtual void step(quantity<si::time, double> elapsed) = 0;
};

#endif

