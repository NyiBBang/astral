#ifndef LOGIC_UNITS_H
#define LOGIC_UNITS_H

#include <boost/units/quantity.hpp>
#include <boost/units/pow.hpp>
#include <boost/units/io.hpp>
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/prefixes.hpp>

using boost::units::quantity;
using boost::units::si::velocity;
using boost::units::si::length;
using boost::units::si::milli;
using boost::units::si::meters;
using boost::units::si::seconds;
using boost::units::si::meters_per_second;
using namespace boost::units;

using TimeQuantity = quantity<si::time, double>;
using SpeedQuantity = quantity<si::velocity, double>;

#endif

