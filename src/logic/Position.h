#ifndef LOGIC_POSITION_H
#define LOGIC_POSITION_H

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using boost::units::quantity;
using boost::units::si::length;

struct Position
{
    quantity<length, double> x;
    quantity<length, double> y;
};

#endif

