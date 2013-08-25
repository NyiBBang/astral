#include "Mover.h"

Mover::Mover(Position& pos)
    : pos_(pos)
{}

void Mover::teleport(int x, int y)
{
    pos_.x = x;
    pos_.y = y;
}

