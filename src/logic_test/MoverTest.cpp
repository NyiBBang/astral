#include "config.h"
#include "logic/Mover.h"

BOOST_AUTO_TEST_CASE(Mover_updates_a_position_when_teleporting)
{
    Position pos;
    Mover mover(pos);
    mover.teleport(42, 24);
    BOOST_CHECK_EQUAL(pos.x, 42);
    BOOST_CHECK_EQUAL(pos.y, 24);
}
