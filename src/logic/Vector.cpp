#include "Vector.h"
#include "Position.h"

LengthVector make_vector(const Position& a, const Position& b)
{
    return {b.x - a.x, b.y - a.y};
}

Direction normalize(const LengthVector& vec)
{
    const quantity<length, double> norm = root<2>(pow<2>(vec.x) + pow<2>(vec.y));
    if (norm == quantity<length, double>(0)) return {0, 0};
    return {vec.x / norm, vec.y / norm};
}

