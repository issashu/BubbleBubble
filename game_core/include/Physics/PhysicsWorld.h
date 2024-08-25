#ifndef B2WORLD_H
#define B2WORLD_H
#include "box2d/id.h"

class b2World;
struct b2WorldDef;

namespace game_core {
class PhysicsWorld {
public:
  explicit PhysicsWorld();
  ~PhysicsWorld();
  b2WorldId GetWorldId() const;
  void UpdateSimulation() const;

private:
  b2WorldId m_worldId;
};

}//namespace game_engine



#endif //B2WORLD_H
