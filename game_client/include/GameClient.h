#ifndef GAMECLIENT_H
#define GAMECLIENT_H

#include <memory>
#include "SDL2/SDL.h"

namespace game_core {
class Renderer;
class PhysicsWorld;
}

namespace game_client {

class GameClient {
public:
  GameClient();
  ~GameClient();

  bool GameInitialize();
  bool GameAssetsLoad();

  bool GetInput(); //TODO Is still only for debugging - fix
  void UpdatePhysics();
  void DrawGraphics() const;
  void DrawGraphicsAndClear() const;
  void PlaySound();

  std::weak_ptr<game_core::PhysicsWorld> GetPhysicsWorld();
  std::weak_ptr<game_core::Renderer> GetRenderer();


private:
  // TODO Add pointers to other systems the game client would need
  std::shared_ptr<game_core::PhysicsWorld> m_physic_world;
  std::shared_ptr<game_core::Renderer> m_renderer;
};
} // namespace game_engine

#endif // GAMECLIENT_H
