#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Components/Component.h"

#include <SDL.h>

namespace game_core {

class Controller: public game_core::Component {
public:
  virtual ~Controller() = default;

  virtual SDL_Event processInput() = 0;
};
}
#endif // CONTROLLER_H