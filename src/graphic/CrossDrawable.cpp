#include "CrossDrawable.h"
#include "Drawer.h"
#include "logic/Position.h"
#include <SFML/Window/OpenGL.hpp>

CrossDrawable::CrossDrawable(const Position& pos, Drawer& drawer)
    : pos_(pos)
    , drawer_(drawer)
{
    drawer_.add(*this);
}

CrossDrawable::~CrossDrawable()
{
    drawer_.remove(*this);
}

void CrossDrawable::draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(pos_.x.value(), pos_.y.value(), 0.);
    glBegin(GL_LINES);
        glVertex2f(-10, 0);
        glVertex2f( 10, 0);
        glVertex2f( 0, -10);
        glVertex2f( 0,  10);
    glEnd();
}

