#ifndef ACTOR_H
#define ACTOR_H
#include <vector>

namespace game_core {
class Component;

enum class EActorStatus {
  alive = 0,
  dead,
  enabled,
  disabled,
  count
};

enum class EActorType {
  player = 0,
  enemy,
  bullet,
  count
};

/////////////////////////////////////////////////////////////
class Actor {
public:
  Actor();
  ~Actor();

  Actor(const Actor &other);

  bool AddComponent(Component *component);
  Component *GetComponent(int index) const;

private:
  std::vector<Component *> m_components;
  EActorStatus status;
};
} // namespace game_core

#endif // ACTOR_H
