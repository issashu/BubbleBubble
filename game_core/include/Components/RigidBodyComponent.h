#ifndef RIGIDBODYBASE_H
#define RIGIDBODYBASE_H

#include "box2d/id.h"
#include "box2d/types.h"

struct b2BodyDef;

namespace game_core {

class RigidBodyComponent {
public:
  // pass by value required by box2d
  explicit RigidBodyComponent(b2WorldId world);
  RigidBodyComponent(b2WorldId world,
            const b2BodyDef *settings);
  ~RigidBodyComponent();

  b2BodyId GetBodyID() const;
  bool isValid() const;
  bool isEnabled() const;
  b2BodyType GetType() const;
  bool isBullet() const;

  void ApplyForce(const b2Vec2 &force, const b2Vec2 &point, bool wake=true) const;
  void ApplyForceToCenter(const b2Vec2 &force, bool wake=true) const;
  void SetGravityScale(float scale) const;
  float GetGravityScale() const;

private:
  b2BodyId m_bodyID{};
};

} // namespace game_engine

#endif // RIGIDBODYBASE_H
