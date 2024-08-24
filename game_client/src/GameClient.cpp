#include "game_client/include/GameClient.h"

#include "Renderer/Renderer.h"
#include "Physics/PhysicsWorld.h"

namespace game_client {

GameClient::GameClient() {
  m_physic_world =
      std::make_shared<game_core::PhysicsWorld>();

  m_renderer = std::make_shared<game_core::Renderer>();
}

GameClient::~GameClient() {

}
void GameClient::UpdatePhysics() {
  //TODO Think how the physics logic shall work. Execute->grab object values
  m_physic_world->UpdateSimulation();
}
void GameClient::DrawGraphics() const {
  //TODO Remove This is in debug mode only! SDL delay does not work, UI is main thread: https://shorturl.at/P0RhS
  m_renderer->RenderClear();
  SDL_Event e;
  bool quit = false;
  while (!quit){
    while (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT){
        quit = true;
      }
      if (e.type == SDL_KEYDOWN){
        quit = true;
      }
      if (e.type == SDL_MOUSEBUTTONDOWN){
        quit = true;
      }
    }
  }
  //m_renderer->RenderAndDelay(12000);
}

std::weak_ptr<game_core::PhysicsWorld> GameClient::GetPhysicsWorld() {
  return m_physic_world;
}
std::weak_ptr<game_core::Renderer> GameClient::GetRenderer() {
  return m_renderer;
}

} // namespace game_client