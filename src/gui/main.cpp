#include "WindowDisplay.h"
#include "logic/StepDispenser.h"
#include "logic/Looper.h"
#include "logic/Chronometer.h"

int main()
{
    StepDispenser dispenser;
    WindowDisplay display(dispenser);
    Chronometer chrono;
    Looper looper(dispenser, display, chrono);
    looper.run();

    return 0;
}
