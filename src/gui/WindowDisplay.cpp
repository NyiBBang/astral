#include "WindowDisplay.h"
#include "logic/StepDispenser.h"
#include <SFML/Graphics.hpp>

WindowDisplay::WindowDisplay(StepDispenser& dispenser)
    : dispenser_(dispenser)
    , window_(new sf::RenderWindow(sf::VideoMode(800, 600), "RTS Game"))
{
    dispenser_.suscribe(*this);
}

WindowDisplay::~WindowDisplay()
{
    dispenser_.unsuscribe(*this);
}

void WindowDisplay::step(quantity<si::time, double>)
{
    sf::Event event;
    while (window_->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window_->close();
    }
    window_->clear();
    window_->display();
}

bool WindowDisplay::shouldStop() const
{
    return !window_->isOpen();
}

