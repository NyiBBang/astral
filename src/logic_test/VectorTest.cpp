#include "config.h"
#include "logic/Position.h"
#include "logic/Vector.h"

BOOST_AUTO_TEST_CASE(make_vector_creates_a_vector_going_from_a_to_b)
{
    const Position a{10 * meters, 15 * meters};
    const Position b{42 * meters, 40 * meters};
    const LengthVector actual = make_vector(a, b);
    const LengthVector expected{32 * meters, 25 * meters};
    BOOST_CHECK_EQUAL(actual.x, expected.x);
    BOOST_CHECK_EQUAL(actual.y, expected.y);
}

