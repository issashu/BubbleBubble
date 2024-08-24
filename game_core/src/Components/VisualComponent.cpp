#include "Components/VisualComponent.h"
#include "Utils/SDLutils.h"

game_core::VisualComponent::VisualComponent(const std::string &filename,
      SDL_Renderer *renderer, int drawLayer)
      : Component(100), m_texture(nullptr), m_drawingLayer(drawLayer) {
        m_texture.reset(SDL_CreateTexture(renderer,
                    SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 20, 20));
}

SDL_Texture *game_core::VisualComponent::GetTexture() const {
  return m_texture.get();
}

int game_core::VisualComponent::GetDrawLayer() const {
  return m_drawingLayer;
}

void game_core::VisualComponent::SetDrawLayer(int drawLayer) {
  m_drawingLayer = drawLayer;
}