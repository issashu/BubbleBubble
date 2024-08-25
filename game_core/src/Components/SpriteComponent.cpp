#include "Components/SpriteComponent.h"
#include "Utils/SDLutils.h"

namespace game_core {

  SpriteComponent::SpriteComponent(int drawLayer, int updateOrder, ESpriteType type)
        : Component(updateOrder), m_drawingLayer(drawLayer){}

  void SpriteComponent::AddTexture(SDL_Texture *texture) {
    m_textures.emplace_back(texture);
  }

  const Textures& SpriteComponent::GetTextures() const {
    return m_textures;
  }

  int SpriteComponent::GetDrawLayer() const {
    return m_drawingLayer;
  }

  void SpriteComponent::SetDrawLayer(int drawLayer) {
    m_drawingLayer = drawLayer;
  }

}