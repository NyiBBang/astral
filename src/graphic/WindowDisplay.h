#ifndef GUI_WINDOW_DISPLAY_H
#define GUI_WINDOW_DISPLAY_H

#include "logic/IStepper.h"
#include "logic/ILoopStopper.h"
#include <memory>

namespace sf
{
    class RenderWindow;
}

class IStepperRegistrar;
class Position;

class WindowDisplay final : private IStepper
                          , public ILoopStopper
{
    public:
        WindowDisplay(IStepperRegistrar& registrar, Position& position);
        ~WindowDisplay();

        bool shouldStop() const override;

    private:
        void step(TimeQuantity elapsed) override;

    private:
        IStepperRegistrar& registrar_;
        Position& position_;
        std::unique_ptr<sf::RenderWindow> window_;
};

#endif

