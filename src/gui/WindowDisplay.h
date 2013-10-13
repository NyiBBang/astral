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

class WindowDisplay final : private IStepper
                          , public ILoopStopper
{
    public:
        WindowDisplay(IStepperRegistrar& registrar);
        ~WindowDisplay();

        virtual bool shouldStop() const override;

    private:
        virtual void step(quantity<si::time, double> elapsed) override;

    private:
        IStepperRegistrar& registrar_;
        std::unique_ptr<sf::RenderWindow> window_;
};

#endif

