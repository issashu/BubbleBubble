#include "Components/SpriteComponent.h"
#include "Utils/SDLutils.h"

namespace game_core {

SpriteComponent::SpriteComponent()
: Component(),  m_type(ESpriteComponentType::count),
  m_drawingLayer(0), m_currentFrame (0), m_animationFPS (0) {

}

void SpriteComponent::AddTexture(SDL_Texture *texture) {
  m_textures.emplace_back(texture);
  m_currentFrame = 0;
}

const Textures &SpriteComponent::GetTextures() const { return m_textures; }

SDL_Texture *SpriteComponent::GetTexture() const {
  return m_textures[m_currentFrame].get();
}

int SpriteComponent::GetDrawLayer() const { return m_drawingLayer; }
int SpriteComponent::GetCurrentDrawFrame() const { return m_currentFrame; }
void SpriteComponent::SetCurrentFrame(int frame) { m_currentFrame = frame; }

void SpriteComponent::Update(float deltaTime) {
  if (m_type == ESpriteComponentType::animation) {
    // Update the current frame based on frame rate and delta time
    m_currentFrame += m_animationFPS * deltaTime;

    // Wrap current frame if needed
    while (m_currentFrame >= m_textures.size()) {
      m_currentFrame -= m_textures.size();
    }
  } else {
    m_currentFrame = 0;
  }
}
void SpriteComponent::Initialize(int drawLayer, int updateOrder,
                                 ESpriteComponentType type, int fps) {
  m_drawingLayer = drawLayer;
  SetUpdateOrder(updateOrder);
  m_type = type;
  m_animationFPS = fps;
}

void SpriteComponent::SetDrawLayer(int drawLayer) {
  m_drawingLayer = drawLayer;
}

} // namespace game_core