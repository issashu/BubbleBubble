#ifndef ACTOR_H
#define ACTOR_H
#include "Components/Component.h"

#include <vector>
#include <unordered_map>

namespace game_core {

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
  terrain,
  bullet,
  count
};

inline std::unordered_map<std::string, EActorTag> actorTagStrings = {
  {"player", EActorTag::player},
  {"enemy", EActorTag::enemy},
  {"terrain", EActorTag::terrain},
  {"bullet", EActorTag::bullet},
  {"none", EActorTag::count}
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

  bool AddComponent(std::unique_ptr<Component> component);
  Component *GetComponent(int index) const;

private:
  std::string m_name;
  EActorStatus m_status;
  EActorTag m_tag;
  std::vector<std::unique_ptr<Component>> m_components;
};
} // namespace game_core

#endif // ACTOR_H
