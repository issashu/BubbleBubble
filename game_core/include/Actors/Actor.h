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

enum class EActorTag {
  player = 0,
  enemy,
  bullet,
  count
};

/////////////////////////////////////////////////////////////
class Actor {
public:
  Actor();
  Actor(std::string name, EActorStatus status, EActorTag tag, int componentsCount = 1);
  ~Actor();

  Actor(const Actor &other);

  void SetName(std::string name);
  void SetStatus(EActorStatus status);
  void SetTag(EActorTag tag);

  bool AddComponent(Component *component);
  Component *GetComponent(int index) const;

private:
  std::string m_name;
  EActorStatus m_status;
  EActorTag m_actorTag;
  std::vector<Component *> m_components;
};
} // namespace game_core

#endif // ACTOR_H
