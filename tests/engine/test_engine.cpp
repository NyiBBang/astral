// Copyright (C) 2018 Vincent PALANCHER (nyibbang)
//
// This file is part of Astral.
//
// Astral is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Astral is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Astral.  If not, see <http://www.gnu.org/licenses/>.

#include <engine/engine.hpp>
#include <gmock/gmock.h>

namespace astral::eng::test
{
TEST(Engine, Run)
{
  testing::MockFunction<bool()> stop;
  testing::MockFunction<void()> update;

  EXPECT_CALL(update, Call()).Times(1);
  EXPECT_CALL(stop, Call())
      .Times(2)
      .WillOnce(testing::Return(false))
      .WillOnce(testing::Return(true));
  astral::eng::run(update.AsStdFunction(), stop.AsStdFunction());
}

} // namespace astral::eng::test
