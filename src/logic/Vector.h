#ifndef LOGIC_VECTOR_H
#define LOGIC_VECTOR_H

#include "Units.h"

struct Position;

struct Direction
{
    double x;
    double y;
};

struct LengthVector
{
    quantity<length, double> x;
    quantity<length, double> y;
};

LengthVector make_vector(const Position& a, const Position& b);
Direction normalize(const LengthVector& vec);

#endif
