#include "WindowDisplay.h"
#include "logic/Looper.h"
#include "logic/Chronometer.h"

int main()
{
    WindowDisplay display;
    Chronometer chrono;
    Looper looper(display, display, chrono);
    looper.run();

    return 0;
}
