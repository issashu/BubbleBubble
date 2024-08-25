#ifndef VISUALCOMPONENT2D_H
#define VISUALCOMPONENT2D_H

#include "Component.h"

#include "Utils/SDLutils.h"
#include <memory>
#include <vector>

namespace game_core {

enum class ESpriteType {
  single = 0,
  animation
};

using Textures = std::vector<std::unique_ptr<SDL_Texture, sdl_deleter>>;

  class SpriteComponent : public Component {
    public:
    explicit SpriteComponent(int drawLayer, int updateOrder, ESpriteType type = ESpriteType::single); // draw layer 0 = background
    ~SpriteComponent() override = default;  //TODO Check for leaks. Don't trust the unique ptr and def destr :P

    void AddTexture(SDL_Texture *texture);
    const Textures& GetTextures() const;

    void SetDrawLayer(int drawLayer);
    int GetDrawLayer() const;

  private:
    Textures m_textures;
    int m_drawingLayer;
  };
}

#endif //VISUALCOMPONENT2D_H
