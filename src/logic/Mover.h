#ifndef LOGIC_MOVER_H
#define LOGIC_MOVER_H

#include "IStepper.h"
#include "Units.h"

class Position;
class IStepperRegistrar;

class Mover final : private IStepper
{
    public:
        Mover(Position& pos, const Position& target,
              SpeedQuantity speed, IStepperRegistrar& registrar);
        ~Mover();

        void teleport() const;
        void step(TimeQuantity elapsed) override;

    private:
        Position& pos_;
        const Position& target_;
        const SpeedQuantity speed_;
        IStepperRegistrar& registrar_;
};

#endif

