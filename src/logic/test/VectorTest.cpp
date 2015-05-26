#include "logic/Position.h"
#include "logic/Vector.h"
#include <gtest/gtest.h>

TEST(LogicTest, make_vector_creates_a_vector_going_from_a_to_b)
{
    const Position a{10 * meters, 15 * meters};
    const Position b{42 * meters, 40 * meters};
    const LengthVector actual = make_vector(a, b);
    const LengthVector expected{32 * meters, 25 * meters};
    EXPECT_EQ(actual.x, expected.x);
    EXPECT_EQ(actual.y, expected.y);
}

TEST(LogicTest, normalized_vector_has_a_norm_of_1)
{
    const LengthVector vec{32 * meters, 25 * meters};
    const Direction direct = normalize(vec);
    EXPECT_DOUBLE_EQ(1., pow<2>(direct.x) + pow<2>(direct.y));
}

TEST(LogicTest, normalized_null_vector_is_null)
{
    const LengthVector vec{0, 0};
    const Direction direct = normalize(vec);
    EXPECT_EQ(direct.x, 0);
    EXPECT_EQ(direct.y, 0);
}

