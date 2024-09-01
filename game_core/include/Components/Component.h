#ifndef COMPONENT_H
#define COMPONENT_H

namespace game_core {
class Actor;

enum class EComponentType {
  TransformComponent = 0,
  RigidBodyComponent,
  InputComponent,
  SpriteComponent,
  AudioComponent,
  NetworkComponent,
  Count
};


class Component{
public:
  // Constructor
  // (the lower the update order, the earlier the component updates)
  explicit Component();
  // Destructor
  virtual ~Component() = 0;
  // Update this component by delta time
  //virtual void Update(float deltaTime) = 0;

  int GetUpdateOrder() const;
  void SetUpdateOrder(int updateOrder);
  void SetOwner(const Actor *owner);
  const Actor *GetOwner() const;

protected:
  // Owning actor
  const Actor* m_Owner;
  // Update order of component
  int m_UpdateOrder;
};
}


#endif //COMPONENT_H
