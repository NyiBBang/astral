#ifndef LOGIC_MOVER_H
#define LOGIC_MOVER_H

struct Position
{
    int x;
    int y;
};

class Mover
{
    public:
        Mover(Position& pos);
        void teleport(int x, int y);

    private:
        Position& pos_;
};

#endif

