#ifndef VISUALCOMPONENT2D_H
#define VISUALCOMPONENT2D_H

#include "Component.h"

#include "Utils/SDLutils.h"
#include <memory>

/*
*  - **Texture**: Reference to the image or sprite sheet.
   - **Source Rect**: The rectangle area of the texture to render.
   - **Color**: Tint color of the sprite.
   - **Layer**: Drawing order or layer.
 */

namespace game_core {
  class VisualComponent : public Component {
    public:
    VisualComponent(const std::string& filename, SDL_Renderer *renderer,
      int drawLayer = 1); //draw layer 0 = background
    ~VisualComponent() = default;  //TODO Check for leaks. Don't trust the unique ptr :P

    SDL_Texture *GetTexture() const;
    int GetDrawLayer() const;

    void SetDrawLayer(int drawLayer);

  private:
    std::unique_ptr<SDL_Texture, sdl_deleter> m_texture;
    int m_drawingLayer;
  };
}

#endif //VISUALCOMPONENT2D_H
