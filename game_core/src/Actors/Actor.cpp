#include "Actors/Actor.h"
#include "Components/Component.h"

namespace game_core {
  Actor::Actor() : status(EActorStatus::enabled) {}
  Actor::~Actor() {}

  bool Actor::AddComponent(Component *component) {
    if (!component) {
      return false;
    }

    component->SetOwner(
        this); // TODO Rethink if component needs to know its owner
    m_components.push_back(component);
    return true;
  }
  Component *Actor::GetComponent(int index) const {
    return m_components[index];
  }
  } // namespace game_core