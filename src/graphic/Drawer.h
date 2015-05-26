#ifndef GUI_DRAWER_H
#define GUI_DRAWER_H

#include "logic/IStepper.h"
#include <vector>

class IStepperRegistrar;
class IDrawable;

class Drawer final : private IStepper
{
    public:
        Drawer(IStepperRegistrar& registrar);
        ~Drawer();

        void add(IDrawable& drawable);
        void remove(IDrawable& drawable);

    private:
        void step(TimeQuantity elapsed) override;

    private:
        IStepperRegistrar& registrar_;
        std::vector<IDrawable*> drawables_;
};

#endif

