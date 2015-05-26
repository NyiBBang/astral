#include "MockStepperRegistrar.h"
#include "logic/Mover.h"
#include "logic/Position.h"
#include "logic/Vector.h"
#include <gtest/gtest.h>

TEST(LogicTest, Mover_sets_a_position_directly_at_a_target_when_teleporting)
{
    Position pos{0, 0};
    const Position target{42 * meters, 24 * meters};
    MockStepperRegistrar registrar;
    EXPECT_CALL(registrar, suscribe(::testing::_));
    Mover mover(pos, target, 0, registrar);
    mover.teleport();
    EXPECT_EQ(pos.x, target.x);
    EXPECT_EQ(pos.y, target.y);
    EXPECT_CALL(registrar, unsuscribe(::testing::_));
}

TEST(LogicTest, Mover_moves_towards_the_target_in_a_straight_line_at_a_static_speed_when_stepped)
{
    const Position init{321 * meters, 3289 * meters};
    const Position target{1230 * meters, 238 * meters};
    const quantity<velocity, double> speed = 100 * meters_per_second;
    const Direction direct = normalize(make_vector(init, target));
    Position pos = init;
    MockStepperRegistrar registrar;
    EXPECT_CALL(registrar, suscribe(::testing::_));
    Mover mover(pos, target, speed, registrar);

    const quantity<si::time, double> elapsed(100.0 * milli * seconds);
    mover.step(elapsed);
    EXPECT_EQ(pos.x, init.x + direct.x * speed * elapsed);
    EXPECT_EQ(pos.y, init.y + direct.y * speed * elapsed);
    EXPECT_CALL(registrar, unsuscribe(::testing::_));
}

