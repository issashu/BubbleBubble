#ifndef RENDERER_H
#define RENDERER_H

#include <cstdint>
#include <memory>
#include "Utils/SDLutils.h"

namespace game_core {
class Renderer {
public:
  Renderer();
  ~Renderer() = default;

  SDL_Renderer* getRenderer() const;

  void Render() const;
  void RenderAndDelay(uint32_t ms) const;
  void RenderClear() const;

private:
  std::unique_ptr<SDL_Window, sdl_deleter> m_window;
  std::unique_ptr<SDL_Renderer, sdl_deleter> m_renderer;
};
}


#endif //RENDERER_H
