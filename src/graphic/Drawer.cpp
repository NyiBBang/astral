#include "Drawer.h"
#include "IDrawable.h"
#include "logic/IStepperRegistrar.h"
#include <SFML/Window/OpenGL.hpp>

Drawer::Drawer(IStepperRegistrar& registrar)
    : registrar_(registrar)
{
    registrar_.suscribe(*this);
}

Drawer::~Drawer()
{
    registrar_.unsuscribe(*this);
}

void Drawer::add(IDrawable& drawable)
{
    drawables_.push_back(&drawable);
}

void Drawer::remove(IDrawable& drawable)
{
    drawables_.erase(std::remove(drawables_.begin(), drawables_.end(), &drawable),
                     drawables_.end());
}

void Drawer::step(quantity<si::time, double>)
{
    for (auto drawable : drawables_)
    {
        glPushMatrix();
        drawable->draw();
        glPopMatrix();
    }
    glFlush();
}

