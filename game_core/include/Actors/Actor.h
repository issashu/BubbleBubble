#ifndef ACTOR_H
#define ACTOR_H
#include <vector>

namespace game_core {
class Component;

class Actor {
public:
  Actor();
  ~Actor();

  bool AddComponent(Component *component);
  void UpdateComponents() const;

private:
  std::vector<Component *> m_components;
};
} // namespace game_core

#endif // ACTOR_H
