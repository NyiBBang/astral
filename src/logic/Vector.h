#ifndef LOGIC_VECTOR_H
#define LOGIC_VECTOR_H

class Position;

struct Vector
{
    double x;
    double y;
};

Vector make_vector(const Position& a, const Position& b);
Vector normalize(const Vector& vec);

#endif

