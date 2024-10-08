#include "GameClient.h"

#include "Components/SpriteComponent.h"
#include "Graphics/Renderer.h"
#include "Physics/PhysicsWorld.h"
#include "SDL_image.h"

#include "nlohmann/json_fwd.hpp"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

namespace game_client {

GameClient::GameClient() {
  GameInitialize();
}

GameClient::~GameClient() {
  // Stop required library systems
  SDL_Quit();
  m_physic_world = nullptr;
  m_renderer = nullptr;
}

bool GameClient::GameInitialize() {
  //Start required library systems
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Init(SDL_INIT_TIMER);
  SDL_Init(SDL_INIT_AUDIO);
  IMG_Init(IMG_INIT_PNG); //TODO Add code to handle when init fails and cleanup

  //Initialise managers
  m_physic_world = std::make_shared<game_core::PhysicsWorld>();
  m_renderer = std::make_shared<game_core::Renderer>();

  return true;
}

bool GameClient::GetInput() {
  SDL_Event event;
  bool quit = false;

  while (SDL_PollEvent(&event)){
    if (event.type == SDL_QUIT){
      quit = true;
    }
    if (event.type == SDL_KEYDOWN){
      quit = false;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN){
      quit = true;
    }
  }

  return quit;
}

void GameClient::UpdatePhysics() {
  //TODO Think how the physics logic shall work. Execute->grab object values
  m_physic_world->UpdateSimulation();
}

void GameClient::DrawGraphics() const {
  // TODO Remove This is in debug mode only! SDL delay does not work, UI is main
  // thread: https://shorturl.at/P0RhS
  m_renderer->Render();
}
void GameClient::DrawGraphicsAndClear() const {
  // TODO Remove This is in debug mode only! SDL delay does not work, UI is main
  // thread: https://shorturl.at/P0RhS
  m_renderer->Render();
  m_renderer->RenderClear();

}

void GameClient::PlaySound() {

}

std::weak_ptr<game_core::PhysicsWorld> GameClient::GetPhysicsWorld() {
  return m_physic_world;
}
std::weak_ptr<game_core::Renderer> GameClient::GetRenderer() {
  return m_renderer;
}

bool GameClient::GameAssetsLoad() {
  using json = nlohmann::ordered_json;

  std::ifstream config_file(ASSETS_DIR"/game_objects_config.json");
  json parsedConfigFile = json::parse(config_file);
  auto numberActors = parsedConfigFile["actors"].size();
  //TODO Initialise GameObject manager pre-allocating fixed size vector for actors
  return true;
}
} // namespace game_client