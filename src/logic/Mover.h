#ifndef LOGIC_MOVER_H
#define LOGIC_MOVER_H

#include "IStepper.h"
#include "Units.h"

class Position;

class Mover final : public IStepper
{
    public:
        Mover(Position& pos, const Position& target,
              quantity<velocity, double> speed);
        void teleport() const;
        virtual void step(quantity<si::time, double> elapsed) override;

    private:
        Position& pos_;
        const Position& target_;
        const quantity<si::velocity, double> speed_;
};

#endif

