#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Component.h"

#include "Utils/SDLutils.h"
#include <memory>
#include <vector>

namespace game_core {

enum class ESpriteComponentType {
  single = 0,
  animation
};

using Texture = std::unique_ptr<SDL_Texture, sdl_deleter>;
using Textures = std::vector<Texture>;

  class SpriteComponent : public Component {
    public:
    explicit SpriteComponent(int drawLayer, int updateOrder, ESpriteComponentType type = ESpriteComponentType::single, int fps = 0); // draw layer 0 = background
    ~SpriteComponent() override = default;  //TODO Check for leaks. Don't trust the unique ptr and def destr :P

    void AddTexture(SDL_Texture *texture);
    const Textures &GetTextures() const;
    SDL_Texture *GetTexture() const;

    void SetDrawLayer(int drawLayer);
    int GetDrawLayer() const;

    int GetCurrentDrawFrame() const;
    void SetCurrentFrame(int frame); //for animation resets

    void Update(float deltaTime);

  private:
    Textures m_textures;
    ESpriteComponentType m_type;
    int m_drawingLayer;
    int m_currentFrame; //TODO Consider if we need uint64_t to keep vector size() happy
    int m_animationFPS;
  };
}

#endif //SPRITECOMPONENT_H
