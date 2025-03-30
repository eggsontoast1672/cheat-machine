#include "cmac/window.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

#include <SDL2/SDL.h>

[[noreturn]]
static void panic(const char *message) {
  std::ostringstream stream;
  stream << "[FATAL] " << message << ": " << SDL_GetError();
  throw std::runtime_error{stream.str()};
}

namespace CMac {

Window::Window(int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    panic("failed to initialize SDL");
  }
  if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &m_window,
                                  &m_renderer) < 0) {
    SDL_Quit();
    panic("failed to create window and renderer");
  }
}

Window::~Window() {
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Window::clear() const {
  if (SDL_RenderClear(m_renderer) < 0) {
    std::cerr << SDL_GetError() << '\n';
  }
}

bool Window::should_close() {
  while (SDL_PollEvent(&m_event)) {
    if (m_event.type == SDL_QUIT) {
      return true;
    }
  }
  return false;
}

} // namespace CMac
