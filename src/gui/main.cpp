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
    WindowDisplay display(dispenser);
    Drawer drawer(dispenser);
    Position pos{100 * meters, 100 * meters};
    CrossDrawable cross(pos, drawer);
    Position target{200 * meters, 200 * meters};
    Mover mover(pos, target, 50 * meters_per_second, dispenser);
    Chronometer chrono;
    Looper looper(dispenser, display, chrono);
    looper.run();

    return 0;
}
