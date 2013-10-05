#ifndef LOGIC_VECTOR_H
#define LOGIC_VECTOR_H

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using namespace boost::units;

class Position;

struct Direction
{
    double x;
    double y;
};

struct LengthVector
{
    quantity<si::length, double> x;
    quantity<si::length, double> y;
};

LengthVector make_vector(const Position& a, const Position& b);
Direction normalize(const LengthVector& vec);

#endif

