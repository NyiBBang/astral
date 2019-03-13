#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/engine.hpp>
#include <functional>

namespace astral::gui
{
namespace
{
void update(sf::RenderWindow& window)
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
  }
  window.display();
}

bool must_stop(const sf::RenderWindow& window)
{
  return !window.isOpen();
}

} // namespace

void start()
{
  auto video_mode = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(std::move(video_mode), "astral");

  eng::run(std::bind(update, std::ref(window)),
                     std::bind(must_stop, std::cref(window)));
}

} // namespace astral::gui
