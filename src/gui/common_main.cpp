#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace astral::gui
{
const auto frame_rate_limit = 60u;

void start()
{
  auto video_mode = sf::VideoMode::getDesktopMode();
  sf::RenderWindow window(std::move(video_mode), "astral");
  window.setFramerateLimit(frame_rate_limit);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    window.display();
  }
}

} // namespace astral::gui
