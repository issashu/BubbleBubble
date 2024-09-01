#include "Components/RigidBodyComponent.h"

#include "box2d/box2d.h"
#include "box2d/id.h"
#include "box2d/types.h"

namespace game_core {
//TODO Add meaningful update order to inits for ALL components

RigidBodyComponent::~RigidBodyComponent() {
  b2DestroyBody(m_bodyID);
}

b2BodyId RigidBodyComponent::GetBodyID() const { return m_bodyID; }

bool RigidBodyComponent::isValid() const {
  return b2Body_IsValid(m_bodyID);
}

bool RigidBodyComponent::isEnabled() const {
  return b2Body_IsEnabled(m_bodyID);
}

b2BodyType RigidBodyComponent::GetType() const {
  return b2Body_GetType(m_bodyID);
}
bool RigidBodyComponent::isBullet() const { return b2Body_IsBullet(m_bodyID); }

void RigidBodyComponent::Initialize(b2WorldId world, const b2BodyDef *settings) {
  m_bodyID = b2CreateBody(world, settings);
}

void RigidBodyComponent::ApplyForce(const b2Vec2 &force, const b2Vec2 &point,
                                    bool wake) const {
  b2Body_ApplyForce(m_bodyID, force, point, wake);
}

void RigidBodyComponent::ApplyForceToCenter(const b2Vec2 &force,
                                            bool wake) const {
  b2Body_ApplyForceToCenter(m_bodyID, force, wake);
}

void RigidBodyComponent::SetGravityScale(float scale) const {
  b2Body_SetGravityScale(m_bodyID, scale);
}

float RigidBodyComponent::GetGravityScale() const {
  return b2Body_GetGravityScale(m_bodyID);
}

} // namespace game_engine