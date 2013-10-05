#include "Vector.h"
#include "Position.h"
#include <cmath>

Vector make_vector(const Position& a, const Position& b)
{
    return {static_cast<double>(a.x - b.x), static_cast<double>(a.y - b.y)};
}

Vector normalize(const Vector& vec)
{
    const double length = std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 3));
    return {vec.x / length, vec.y / length};
}

