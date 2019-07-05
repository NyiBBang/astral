// Copyright (C) 2019 Vincent PALANCHER (nyibbang)
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

#include "event_handler.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <cassert>

namespace astral::gui {
using namespace std;
using namespace sf;

constexpr auto window_title = "astral";
constexpr auto frame_rate_limit = 60u;
constexpr auto zoom_sensitivity = 0.1f;

namespace {

/// @returns The zoom factor applied to the view.
float zoom_target_view(RenderTarget& target, float delta) {
  auto view = target.getView();
  const auto factor = 1.f - delta * zoom_sensitivity;
  view.zoom(factor);
  target.setView(view);
  return factor;
}

class Zoom_target_view_on_wheel_scroll : public Event_handler {
public:
  Zoom_target_view_on_wheel_scroll(RenderTarget& target) : _target(&target) {
  }

private:
  void execute(const Event& ev) noexcept override {
    if (!_target || ev.type != Event::MouseWheelScrolled)
      return;

    const auto& scroll = ev.mouseWheelScroll;
    if (scroll.wheel != Mouse::VerticalWheel)
      return;

    assert(_target != nullptr);
    zoom_target_view(*_target, scroll.delta);
  }

  RenderTarget* _target = nullptr;
};

class Close_window : public Event_handler {
public:
  Close_window(Window& window) : _window(&window) {
  }

private:
  void execute(const Event& ev) noexcept override {
    if (!_window || ev.type != Event::Closed)
      return;

    assert(_window != nullptr);
    _window->close();
  }

  Window* _window = nullptr;
};

} // namespace

void start() {
  auto video_mode = VideoMode::getDesktopMode();

  auto settings = ContextSettings();
  settings.antialiasingLevel = 8;

  auto window =
      RenderWindow(move(video_mode), window_title, Style::Default, settings);
  window.setFramerateLimit(frame_rate_limit);

  auto view = window.getDefaultView();

  auto circle = CircleShape(30);
  circle.setOutlineColor(Color::Blue);
  circle.setOutlineThickness(2);
  circle.setFillColor(Color::Green);
  circle.setPosition(10, 20);

  // TODO: Avoid executing all handlers on each event because it's a lot of
  // indirections.
  auto event_handlers = [&] {
    vector<unique_ptr<Event_handler>> vec;
    vec.reserve(2);
    vec.emplace_back(make_unique<Close_window>(window));
    vec.emplace_back(make_unique<Zoom_target_view_on_wheel_scroll>(window));
    return vec;
  }();

  while (window.isOpen()) {
    auto event = Event();
    while (window.pollEvent(event)) {
      for (const auto& handler : event_handlers)
        (*handler)(event);

      // case Event::MouseButtonPressed: {
      //   if (event.mouseButton.button == Mouse::Left) {
      //     const auto local_mouse_pos =
      //         Vector2i(event.mouseButton.x, event.mouseButton.y);
      //     const auto world_coords = window.mapPixelToCoords(local_mouse_pos);
      //     const auto circle_bounds = circle.getGlobalBounds();
      //     if (circle_bounds.contains(world_coords.x, world_coords.y)) {
      //       circle.setOutlineColor(Color::Red);
      //     } else {
      //       circle.setOutlineColor(Color::Blue);
      //     }
      //   }
      //   break;
      // }
      // case Event::Resized: {
      //   auto visible_area =
      //       FloatRect(0.f, 0.f, static_cast<float>(event.size.width),
      //                 static_cast<float>(event.size.height));
      //   view.setSize(visible_area.width, visible_area.height);
      //   window.setView(view);
      //   break;
      // }
    }

    window.clear();
    window.draw(circle);
    window.display();
  }
}

} // namespace astral::gui
