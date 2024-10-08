#include "Actors/Actor.h"

#include <utility>
#include "Components/Component.h"

namespace game_core {
  Actor::Actor()
    : m_name (""), m_status(EActorStatus::disabled), m_tag(EActorTag::count) {
    m_components.reserve(1);
  }

  Actor::Actor(std::string name, EActorStatus status, EActorTag tag, int componentsCount)
    : m_name(std::move(name)), m_status(status), m_tag(tag) {
    m_components.reserve(componentsCount);
  }

  Actor::~Actor() = default;
  void Actor::SetName(std::string name) {
   m_name = std::move(name);
  }

  void Actor::SetStatus(const EActorStatus status) {
    m_status = status;
  }

  void Actor::SetTag(const EActorTag tag) {
    m_tag = tag;
  }

  bool Actor::AddComponent(std::unique_ptr<Component> component) {
    if (!component) {
      return false;
    }

    component->SetOwner(this); // TODO Rethink if component needs to know its owner
    m_components.push_back(std::move(component));
    return true;
  }

  Component *Actor::GetComponent(const int index) const {
    return m_components[index].get();
  }
  } // namespace game_core