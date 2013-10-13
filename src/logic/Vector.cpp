#include "Vector.h"
#include "Position.h"

LengthVector make_vector(const Position& a, const Position& b)
{
    return {b.x - a.x, b.y - a.y};
}

Direction normalize(const LengthVector& vec)
{
    const quantity<length, double> length = root<2>(pow<2>(vec.x) + pow<2>(vec.y));
    return {vec.x / length, vec.y / length};
}

