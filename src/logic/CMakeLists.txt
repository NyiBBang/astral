set(logic_SOURCES
    Chronometer.cpp Chronometer.h
    IChronometer.h ILoopStopper.h
    IStepper.h IStepperRegistrar.h
    Looper.cpp Looper.h
    Mover.cpp Mover.h
    Position.h Units.h
    StepDispenser.cpp StepDispenser.h
    Vector.cpp Vector.h
)
add_library(logic ${logic_SOURCES})

add_subdirectory(test)

