#include "Mover.h"
#include "Position.h"
#include "Vector.h"

Mover::Mover(Position& pos, const Position& target, double speed)
    : pos_(pos)
    , target_(target)
    , speed_(speed)
{}

void Mover::teleport() const
{
    pos_.x = target_.x;
    pos_.y = target_.y;
}

void Mover::step(long elapsed)
{
    const Vector normDirec = normalize(make_vector(pos_, target_));
    pos_.x += normDirec.x * speed_ * elapsed / 1000;
    pos_.y += normDirec.y * speed_ * elapsed / 1000;
}

