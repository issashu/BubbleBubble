#include "main.h"
#include "Actors/Actor.h"
#include "Components/SpriteComponent.h"
#include "GameClient.h"

#include "Graphics/Renderer.h"

int main() {
  //TODO Add a gameInit method
  auto client = game_client::GameClient();

  //TODO Add game loop here
  /*
   * Handle input
   * Send to server
   * Wait for logic from server
   * Update objects
   * Draw screen
   * Play sounds
   */

  //TODO Remove DEBUG calls below
  auto spritePath = std::string(ASSETS_DIR) + "/images/TestSprite.png";
  SDL_Surface *screenSurface = IMG_Load(spritePath.c_str());

  auto renderer = client.GetRenderer().lock();
  auto rendFull = renderer->getRenderer();
  auto texture = SDL_CreateTextureFromSurface(rendFull, screenSurface);

  auto actor = game_core::Actor();
  auto spriteComponent = game_core::SpriteComponent(1,1,
    game_core::ESpriteComponentType::single, 30);
  actor.AddComponent(&spriteComponent);
  auto spriteComp = dynamic_cast<game_core::SpriteComponent*>(actor.GetComponent(0));
  spriteComp->AddTexture(texture);

  auto quit = false;
  while(!quit) {
    quit = client.GetInput();
    client.UpdatePhysics();
    client.DrawGraphicsAndClear();
    SDL_RenderCopy(rendFull, spriteComp->GetTexture(),nullptr, nullptr);
  }

  //To here
}