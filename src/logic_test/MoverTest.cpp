#include "config.h"
#include "logic/Mover.h"
#include "logic/Position.h"
#include "logic/Vector.h"
#include <boost/units/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

BOOST_AUTO_TEST_CASE(Mover_sets_a_position_directly_at_a_target_when_teleporting)
{
    Position pos{0, 0};
    const Position target{42 * si::meters, 24 * si::meters};
    Mover mover(pos, target, 0);
    mover.teleport();
    BOOST_CHECK_EQUAL(pos.x, target.x);
    BOOST_CHECK_EQUAL(pos.y, target.y);
}

BOOST_AUTO_TEST_CASE(Mover_moves_towards_the_target_in_a_straight_line_at_a_static_speed_when_stepped)
{
    const Position init{321 * si::meters, 3289 * si::meters};
    const Position target{1230 * si::meters, 238 * si::meters};
    const quantity<si::velocity, double> speed = 100 * si::meters_per_second;
    const Direction direct = normalize(make_vector(init, target));
    Position pos = init;
    Mover mover(pos, target, speed);

    using boost::units::si::milli;
    using boost::units::si::seconds;
    const quantity<si::time, double> elapsed(100.0 * milli * seconds);
    mover.step(elapsed);
    BOOST_CHECK_EQUAL(pos.x, init.x + direct.x * speed * elapsed);
    BOOST_CHECK_EQUAL(pos.y, init.y + direct.y * speed * elapsed);
}

