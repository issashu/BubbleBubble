#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Components/Controllers/Controller.h"
#include <SDL.h>

namespace game_core {

class PlayerController final : public Controller {
public:
  PlayerController();

  // Method to process input and return corresponding SDL event
  SDL_Event processInput() override;

private:
  void handleKeyboardInput(SDL_Event& event);
  void handleGamepadInput(SDL_Event& event);
};
}

#endif // PLAYER_CONTROLLER_H