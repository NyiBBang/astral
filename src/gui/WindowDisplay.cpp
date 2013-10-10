#include "WindowDisplay.h"
#include <SFML/Graphics.hpp>

WindowDisplay::WindowDisplay()
    : window_(new sf::RenderWindow(sf::VideoMode(800, 600), "RTS Game"))
{}

WindowDisplay::~WindowDisplay()
{}

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
