#ifndef LOGIC_MOVER_H
#define LOGIC_MOVER_H

#include "IStepper.h"
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si.hpp>

using boost::units::quantity;
using boost::units::si::velocity;

class Position;

class Mover final : public IStepper
{
    public:
        Mover(Position& pos, const Position& target,
              quantity<si::velocity, double> speed);
        void teleport() const;
        virtual void step(quantity<si::time, double> elapsed) override;

    private:
        Position& pos_;
        const Position& target_;
        const quantity<si::velocity, double> speed_;
};

#endif

