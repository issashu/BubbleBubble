#include "Actors/Actor.h"

#include <utility>
#include "Components/Component.h"

namespace game_core {
  Actor::Actor()
    : m_name (""), m_status(EActorStatus::disabled), m_actorTag(EActorTag::count) {
    m_components.reserve(1);
  }

  Actor::Actor(std::string name, EActorStatus status, EActorTag tag, int componentsCount)
    : m_name(std::move(name)), m_status(status), m_actorTag(tag) {
    m_components.reserve(componentsCount);
  }

  Actor::~Actor() {}

  bool Actor::AddComponent(Component *component) {
    if (!component) {
      return false;
    }

    component->SetOwner(this); // TODO Rethink if component needs to know its owner
    m_components.push_back(component);
    return true;
  }

  Component *Actor::GetComponent(int index) const {
    return m_components[index];
  }
  } // namespace game_core