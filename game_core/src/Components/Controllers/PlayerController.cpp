#include "Components/Controllers/PlayerController.h"
#include <iostream>

namespace game_core{
PlayerController::PlayerController() {
    if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0) {
        std::cerr << "Failed to initialize SDL game controller: " << SDL_GetError() << std::endl;
    } else {
        // TODO Research how to select other controllers and add user choice
        if (SDL_NumJoysticks() > 0) {
            SDL_GameController* controller = SDL_GameControllerOpen(0);
            if (controller == nullptr) {
                std::cerr << "Could not open game controller: " << SDL_GetError() << std::endl;
            }
        }
    }
}

SDL_Event PlayerController::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            handleKeyboardInput(event);
        } else if (event.type == SDL_CONTROLLERAXISMOTION ||
                   event.type == SDL_CONTROLLERBUTTONDOWN ||
                   event.type == SDL_CONTROLLERBUTTONUP) {
            handleGamepadInput(event);
        }
    }
    return event;
}

void PlayerController::handleKeyboardInput(SDL_Event& event) {
    //TODO Add actual game commands instead of debug prints
    switch (event.key.keysym.sym) {
        case SDLK_w:
            std::cout << "Move up" << std::endl;
            break;
        case SDLK_s:
            std::cout << "Move down" << std::endl;
            break;
        case SDLK_a:
            std::cout << "Move left" << std::endl;
            break;
        case SDLK_d:
            std::cout << "Move right" << std::endl;
            break;
        default:
            break;
    }
}

void PlayerController::handleGamepadInput(SDL_Event& event) {
    //TODO Add actual game commands instead of debug prints
    if (event.type == SDL_CONTROLLERBUTTONDOWN) {
        switch (event.cbutton.button) {
            case SDL_CONTROLLER_BUTTON_A:
                std::cout << "GamePad Button A pressed" << std::endl;
                break;
            case SDL_CONTROLLER_BUTTON_B:
                std::cout << "GamePad Button B pressed" << std::endl;
                break;
            case SDL_CONTROLLER_BUTTON_X:
                std::cout << "GamePad Button X pressed" << std::endl;
                break;
            case SDL_CONTROLLER_BUTTON_Y:
                std::cout << "GamePad Button Y pressed" << std::endl;
                break;
            default:
                break;
        }
    } else if (event.type == SDL_CONTROLLERBUTTONUP) {
        switch (event.cbutton.button) {
            case SDL_CONTROLLER_BUTTON_A:
                std::cout << "GamePad Button A released" << std::endl;
                break;
            case SDL_CONTROLLER_BUTTON_B:
                std::cout << "GamePad Button B released" << std::endl;
                break;
            case SDL_CONTROLLER_BUTTON_X:
                std::cout << "GamePad Button X released" << std::endl;
                break;
            case SDL_CONTROLLER_BUTTON_Y:
                std::cout << "GamePad Button Y released" << std::endl;
                break;
            default:
                break;
        }
    }
}
}