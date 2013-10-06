#include "Mover.h"
#include "Position.h"
#include "Vector.h"

Mover::Mover(Position& pos, const Position& target,
             quantity<si::velocity, double> speed)
    : pos_(pos)
    , target_(target)
    , speed_(speed)
{}

void Mover::teleport() const
{
    pos_.x = target_.x;
    pos_.y = target_.y;
}

void Mover::step(quantity<si::time, double> elapsed)
{
    const Direction direct = normalize(make_vector(pos_, target_));
    pos_.x += direct.x * (speed_ * elapsed);
    pos_.y += direct.y * (speed_ * elapsed);
}

