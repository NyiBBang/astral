#include "WindowDisplay.h"
#include "Drawer.h"
#include "CrossDrawable.h"
#include "logic/Position.h"
#include "logic/StepDispenser.h"
#include "logic/Looper.h"
#include "logic/Chronometer.h"
#include "logic/Mover.h"

int main()
{
    StepDispenser dispenser;
    Position target{0, 0};
    WindowDisplay display(dispenser, target);
    Drawer drawer(dispenser);
    Position pos{0, 0};
    CrossDrawable cross(pos, drawer);
    Mover mover(pos, target, 100 * meters_per_second, dispenser);
    Chronometer chrono;
    Looper looper(dispenser, display, chrono);
    looper.run();

    return 0;
}
