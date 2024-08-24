#include "Renderer/Renderer.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_video.h"


game_core::Renderer::Renderer() : m_window(nullptr), m_renderer(nullptr) {
  // TODO Add options struct and pass it to the constructor
  SDL_Init(SDL_INIT_VIDEO);

  m_window.reset(SDL_CreateWindow("LoremWinsum", SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN));

  m_renderer.reset (SDL_CreateRenderer(m_window.get(), -1,
                        SDL_RENDERER_ACCELERATED));

  SDL_SetRenderDrawColor(m_renderer.get(), 96, 128, 255, 255);
}

void game_core::Renderer::Render() const {
  SDL_RenderPresent(m_renderer.get());
}

void game_core::Renderer::RenderAndDelay(uint32_t ms) const {
  Render();
  SDL_Delay(ms);
}

void game_core::Renderer::RenderClear() const {
  SDL_RenderClear(m_renderer.get());
}