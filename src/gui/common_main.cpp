#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace astral::gui {
using namespace std;
using namespace sf;

constexpr auto frame_rate_limit = 60u;
constexpr auto zoom_sensitivity = 0.1f;

void start() {
  auto video_mode = VideoMode::getDesktopMode();
  
  ContextSettings settings;
  settings.antialiasingLevel = 8;

  RenderWindow window(move(video_mode), "astral", Style::Default, settings);
  window.setFramerateLimit(frame_rate_limit);

  View view = window.getDefaultView();

  CircleShape circle(30);
  circle.setOutlineColor(Color::Blue);
  circle.setOutlineThickness(2);
  circle.setFillColor(Color::Green);
  circle.setPosition(10, 20);

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case Event::Closed:
        window.close();
        break;
      case Event::MouseWheelScrolled: {
        if (event.mouseWheelScroll.wheel == Mouse::VerticalWheel) {
          view.zoom(1.f - event.mouseWheelScroll.delta * zoom_sensitivity);
          window.setView(view);
        }
        break;
      }
      case Event::MouseButtonPressed: {
        if (event.mouseButton.button == Mouse::Left) {
          const auto local_mouse_pos =
              Vector2i(event.mouseButton.x, event.mouseButton.y);
          const auto world_coords = window.mapPixelToCoords(local_mouse_pos);
          const auto circle_bounds = circle.getGlobalBounds();
          if (circle_bounds.contains(world_coords.x, world_coords.y)) {
            circle.setOutlineColor(Color::Red);
          } else {
            circle.setOutlineColor(Color::Blue);
          }
        }
        break;
      }
      case Event::Resized: {
        FloatRect visible_area(0.f, 0.f, static_cast<float>(event.size.width),
                               static_cast<float>(event.size.height));
        view.setSize(visible_area.width, visible_area.height);
        window.setView(view);
        break;
      }
      case Event::LostFocus:
      case Event::GainedFocus:
      case Event::TextEntered:
      case Event::KeyPressed:
      case Event::KeyReleased:
      case Event::MouseWheelMoved:
      case Event::MouseButtonReleased:
      case Event::MouseMoved:
      case Event::MouseEntered:
      case Event::MouseLeft:
      case Event::JoystickButtonPressed:
      case Event::JoystickButtonReleased:
      case Event::JoystickMoved:
      case Event::JoystickConnected:
      case Event::JoystickDisconnected:
      case Event::TouchBegan:
      case Event::TouchMoved:
      case Event::TouchEnded:
      case Event::SensorChanged:
      case Event::Count:
        break;
      }
    }

    window.clear();
    window.draw(circle);
    window.display();
  }
}

} // namespace astral::gui
