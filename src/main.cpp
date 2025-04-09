#include "cmac/window.hpp"

#include <cstddef>

void draw_board(CMac::Window &window) {
  const SDL_Color light = {0xff, 0xff, 0xff, 0xff};
  const SDL_Color dark = {0xff, 0x00, 0x00, 0xff};
  const CMac::Vector2<int> window_size = window.get_size();
  const float square_width = window_size.x / 8.0f;
  const float square_height = window_size.y / 8.0f;

  SDL_Renderer *renderer = window.get_renderer();
  for (std::size_t y = 0; y < 8; y++) {
    for (std::size_t x = 0; x < 8; x++) {
      SDL_Color color = (x + y) % 2 == 0 ? light : dark;
      SDL_FRect rect = {x * square_width, y * square_height, square_width,
                        square_height};
      SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
      SDL_RenderFillRect(renderer, &rect);
    }
  }
}

int main() {
  static constexpr int g_screen_size = 600;

  CMac::Window window{g_screen_size, g_screen_size, "Cheat Machine"};

  while (!window.should_close()) {
    window.clear();
    draw_board(window);
    window.display();
  }
}
