set(logic_test_SOURCES
    config.cpp
    MockChronometer.h
    MockLoopStopper.h
    MockStepper.h
    MockStepperRegistrar.h
    ChronometerTest.cpp
    LooperTest.cpp
    MoverTest.cpp
    StepDispenserTest.cpp
    VectorTest.cpp
)
add_executable(logic_test ${logic_test_SOURCES})
add_test(NAME logic_test COMMAND logic_test)

target_include_directories(logic_test
    PUBLIC
        ${gmock_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}/include
)

target_link_libraries(logic_test
    logic
    gmock_main
)

