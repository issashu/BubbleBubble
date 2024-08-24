#include "Physics/PhysicsWorld.h"
#include "box2d/box2d.h"
#include "box2d/types.h"

namespace game_core {

typedef struct GameSettings {
  b2WorldDef worldDef;
  b2BodyDef bodyDef;
} GameSettings;

PhysicsWorld::PhysicsWorld() {
  // TODO Hardcoded defaults - Make engine read from xml or something similar in struct above
  b2WorldDef settings = b2DefaultWorldDef();
  m_worldId = b2CreateWorld(&settings);
}

PhysicsWorld::~PhysicsWorld() {
  if(b2World_IsValid(m_worldId)) {
    b2DestroyWorld(m_worldId);
  }
}

b2WorldId PhysicsWorld::GetWorldId() const {
  return m_worldId;
}

void PhysicsWorld::UpdateSimulation() const {
  b2World_Step(m_worldId,1/60,4); //TODO Check how to use the world settings here, not hardcode
}

} // namespace game_engine