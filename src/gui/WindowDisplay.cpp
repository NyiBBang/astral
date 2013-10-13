#include "WindowDisplay.h"
#include "logic/IStepperRegistrar.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#define WIDTH 800
#define HEIGHT 600

WindowDisplay::WindowDisplay(IStepperRegistrar& registrar)
    : registrar_(registrar)
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
    while (window_->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_->close();
        else if (event.type == sf::Event::Resized)
        {
            glMatrixMode(GL_PROJECTION);
            glViewport(0, 0, event.size.width, event.size.height);
            glMatrixMode(GL_MODELVIEW);
        }
    }

    window_->display();
}

bool WindowDisplay::shouldStop() const
{
    return !window_->isOpen();
}

