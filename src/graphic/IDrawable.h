#ifndef GUI_I_DRAWABLE_H
#define GUI_I_DRAWABLE_H

class IDrawable
{
    public:
        IDrawable() {}
        ~IDrawable() {}

        virtual void draw() = 0;
};

#endif

