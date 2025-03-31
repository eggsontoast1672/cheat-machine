#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace CMac {

template <typename T> struct Vector2 {
  T x;
  T y;
};

class Window {
public:
  Window(int width, int height, const char *title);
  ~Window();

  void clear() const;
  Vector2<int> get_size() const;
  bool should_close();

  inline void display() const { SDL_RenderPresent(m_renderer); }
  inline SDL_Renderer *get_renderer() { return m_renderer; }

private:
  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  SDL_Event m_event;
};

} // namespace CMac
