#include "Components/Component.h"

namespace game_core {

  Component::Component()
    : m_Owner(nullptr), m_UpdateOrder(0) {}

  Component::~Component() {}

  int Component::GetUpdateOrder() const { return m_UpdateOrder; }
  void Component::SetUpdateOrder(int updateOrder) {
    m_UpdateOrder = updateOrder;
  }

  void Component::SetOwner(const Actor* owner) {
    m_Owner = owner; //TODO Shallow copy - check if we need to make deep overload
  }

  const Actor* Component::GetOwner() const {
      return m_Owner;
  }


  } // namespace game_core