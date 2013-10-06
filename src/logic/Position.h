#ifndef LOGIC_POSITION_H
#define LOGIC_POSITION_H

#include "Units.h"

struct Position
{
    quantity<length, double> x;
    quantity<length, double> y;
};

#endif

