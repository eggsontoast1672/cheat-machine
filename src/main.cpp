#include <cstddef>

#include <SFML/Graphics.hpp>

const sf::Color light{0xff, 0xff, 0xff};
const sf::Color dark{0xff, 0x00, 0x00};

sf::Vector2f get_square_size(const sf::RenderWindow &window) {
  sf::Vector2u window_size = window.getSize();
  return sf::Vector2f{
      window_size.x / 8.0f,
      window_size.y / 8.0f,
  };
}

void draw_board(sf::RenderWindow &window) {
  sf::Vector2f square_size = get_square_size(window);
  sf::RectangleShape rect{square_size};

  for (std::size_t y = 0; y < 8; y++) {
    for (std::size_t x = 0; x < 8; x++) {
      if ((x + y) % 2 == 0) {
        rect.setFillColor(light);
      } else {
        rect.setFillColor(dark);
      }

      sf::Transform transform;
      transform.translate(x * square_size.x, y * square_size.y);
      window.draw(rect, sf::RenderStates{transform});
    }
  }
}

int main() {
  sf::RenderWindow window{sf::VideoMode{600, 600}, "Cheat Machine"};
  window.setFramerateLimit(60);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    draw_board(window);
    window.display();
  }
}
