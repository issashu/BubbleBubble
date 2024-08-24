#include "Actors/Actor.h"
#include "Components/Component.h"

namespace game_core {
  Actor::Actor() {}
  Actor::~Actor() {}

  bool Actor::AddComponent(Component *component) {
    if (!component) { return false;}

    component->SetOwner(this); //TODO Rethink if component needs to know its owner
    m_components.push_back(component);

    return true;
  }
}// namespace game_core