#ifndef GUI_CROSS_DRAWABLE_H
#define GUI_CROSS_DRAWABLE_H

#include "IDrawable.h"

struct Position;
class Drawer;

class CrossDrawable final : public IDrawable
{
    public:
        CrossDrawable(const Position& pos, Drawer& drawer);
        ~CrossDrawable();

        virtual void draw();

    private:
        const Position& pos_;
        Drawer& drawer_;
};

#endif

