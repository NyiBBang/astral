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
add_library(logic STATIC ${logic_SOURCES})
target_include_directories(logic PUBLIC ${Boost_INCLUDE_DIR})

add_subdirectory(test)

