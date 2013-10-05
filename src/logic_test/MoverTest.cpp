#include "config.h"
#include "logic/Mover.h"
#include "logic/Position.h"
#include "logic/Vector.h"
#include <cmath>

BOOST_AUTO_TEST_CASE(Mover_sets_a_position_directly_at_a_target_when_teleporting)
{
    Position pos{0, 0};
    const Position target{42, 24};
    Mover mover(pos, target, 0);
    mover.teleport();
    BOOST_CHECK_EQUAL(pos.x, target.x);
    BOOST_CHECK_EQUAL(pos.y, target.y);
}

BOOST_AUTO_TEST_CASE(Mover_moves_towards_the_target_in_a_straight_line_at_a_static_speed_when_stepped)
{
    const Position initPos{321, 3289};
    const Position target{1230, 238};
    const int speed = 100;
    const Vector normDirect = normalize(make_vector(initPos, target));
    Position pos = initPos;
    Mover mover(pos, target, speed);

    const long elapsed = 100;
    mover.step(elapsed);
    BOOST_CHECK_EQUAL(pos.x, initPos.x + normDirect.x * speed * elapsed / 1000);
    BOOST_CHECK_EQUAL(pos.y, initPos.y + normDirect.y * speed * elapsed / 1000);
}

