#include "WindowDisplay.h"
#include "logic/Position.h"
#include "logic/IStepperRegistrar.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/OpenGL.hpp>

#define WIDTH 800
#define HEIGHT 600

WindowDisplay::WindowDisplay(IStepperRegistrar& registrar, Position& position)
    : registrar_(registrar)
    , position_(position)
    , window_(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "RTS Game"))
{
    registrar_.suscribe(*this);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, WIDTH, HEIGHT);
    glOrtho(0, WIDTH, 0, HEIGHT, 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

WindowDisplay::~WindowDisplay()
{
    registrar_.unsuscribe(*this);
}

void WindowDisplay::step(quantity<si::time, double>)
{
    sf::Event event;
    while (window_->GetEvent(event))
    {
        if (event.Type == sf::Event::Closed)
            window_->Close();
        else if (event.Type == sf::Event::Resized)
        {
            glMatrixMode(GL_PROJECTION);
            glViewport(0, 0, event.Size.Width, event.Size.Height);
            glMatrixMode(GL_MODELVIEW);
        }
        else if (event.Type == sf::Event::MouseButtonReleased)
        {
            // This needs to use 3D projection coordinates conversion
            const int worldY = window_->GetView().GetRect().Top - event.MouseButton.Y;
            position_.x = event.MouseButton.X * meters;
            position_.y = worldY * meters;
        }
    }

    window_->Display();
}

bool WindowDisplay::shouldStop() const
{
    return !window_->IsOpened();
}

