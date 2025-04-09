#include "cmac/window.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

#include <SDL3/SDL.h>

[[noreturn]]
static void panic(const char *message) {
  std::ostringstream stream;
  stream << "[FATAL] " << message << ": " << SDL_GetError();
  throw std::runtime_error{stream.str()};
}

namespace CMac {

Window::Window(int width, int height, const char *title) {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    panic("failed to initialize SDL");
  }

  constexpr Uint32 flags = SDL_WINDOW_RESIZABLE;
  m_window = SDL_CreateWindow(title, width, height, flags);
  if (m_window == nullptr) {
    SDL_Quit();
    panic("failed to create window");
  }

  m_renderer = SDL_CreateRenderer(m_window, nullptr);
  if (m_renderer == nullptr) {
    SDL_DestroyWindow(m_window);
    SDL_Quit();
    panic("failed to create renderer");
  }
}

Window::~Window() {
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Window::clear() const {
  if (!SDL_RenderClear(m_renderer)) {
    std::cerr << SDL_GetError() << '\n';
  }
}

Vector2<int> Window::get_size() const {
  Vector2<int> size;
  SDL_GetWindowSize(m_window, &size.x, &size.y);
  return size;
}

bool Window::should_close() {
  while (SDL_PollEvent(&m_event)) {
    if (m_event.type == SDL_EVENT_QUIT) {
      return true;
    }
  }
  return false;
}

} // namespace CMac
