#pragma once

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace CMac {

class Window {
public:
  Window(int width, int height);
  ~Window();

  void clear() const;
  inline void display() const { SDL_RenderPresent(m_renderer); }
  bool should_close();

private:
  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  SDL_Event m_event;
};

} // namespace CMac
