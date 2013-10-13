#include "config.h"
#include "MockStepperRegistrar.h"
#include "logic/Mover.h"
#include "logic/Position.h"
#include "logic/Vector.h"

BOOST_AUTO_TEST_CASE(Mover_sets_a_position_directly_at_a_target_when_teleporting)
{
    Position pos{0, 0};
    const Position target{42 * meters, 24 * meters};
    MockStepperRegistrar registrar;
    MOCK_EXPECT(registrar.suscribe).once();
    Mover mover(pos, target, 0, registrar);
    mover.teleport();
    BOOST_CHECK_EQUAL(pos.x, target.x);
    BOOST_CHECK_EQUAL(pos.y, target.y);
    MOCK_EXPECT(registrar.unsuscribe).once();
}

BOOST_AUTO_TEST_CASE(Mover_moves_towards_the_target_in_a_straight_line_at_a_static_speed_when_stepped)
{
    const Position init{321 * meters, 3289 * meters};
    const Position target{1230 * meters, 238 * meters};
    const quantity<velocity, double> speed = 100 * meters_per_second;
    const Direction direct = normalize(make_vector(init, target));
    Position pos = init;
    MockStepperRegistrar registrar;
    MOCK_EXPECT(registrar.suscribe).once();
    Mover mover(pos, target, speed, registrar);

    const quantity<si::time, double> elapsed(100.0 * milli * seconds);
    mover.step(elapsed);
    BOOST_CHECK_EQUAL(pos.x, init.x + direct.x * speed * elapsed);
    BOOST_CHECK_EQUAL(pos.y, init.y + direct.y * speed * elapsed);
    MOCK_EXPECT(registrar.unsuscribe).once();
}

