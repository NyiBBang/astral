#ifndef LOGIC_MOVER_H
#define LOGIC_MOVER_H

#include "IStepper.h"

class Position;

class Mover final : public IStepper
{
    public:
        Mover(Position& pos, const Position& target, double speed);
        void teleport() const;
        virtual void step(long elapsed) override;

    private:
        Position& pos_;
        const Position& target_;
        const double speed_;
};

#endif

