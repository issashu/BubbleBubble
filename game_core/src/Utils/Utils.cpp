#include <string>
#include <any>

#include "Components/Component.h"
#include "Utils/Utils.h"

#include "Components/InputComponent.h"
#include "Components/RigidBodyComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"

#include <functional>
#include <typeindex>

namespace game_core {
using CreateFunction = std::function<std::unique_ptr<Component>()>;

std::unordered_map<std::string, CreateFunction> factoryMap;
std::unordered_map<std::string, std::any> actorComponents = { //TODO Check do we really need any, considering we have type_index everywhere
  {"Transform" , std::type_index(typeid(TransformComponent))},
  {"Sprite", std::type_index(typeid(SpriteComponent))},
  {"Body", std::type_index(typeid(RigidBodyComponent))},
  {"Input", std::type_index(typeid(InputComponent))},
};

template<typename T>
    void registerComponent(const std::string& typeName) {
  factoryMap[typeName] = []() -> std::unique_ptr<Component> {
    return std::make_unique<T>();
  };
}

std::unique_ptr<Component> createComponent(const std::string& typeName) {
  auto it = factoryMap.find(typeName);
  if (it != factoryMap.end()) {
    return it->second();
  }
  return nullptr;
}


std::unique_ptr<Component> GetComponentFromString(const std::string& name) {
  if (const auto it = factoryMap.find(name); it == factoryMap.end()) { // TODO Read more about the if-init C++17
    if (const auto typeIndex = std::any_cast<std::type_index>(actorComponents[name]);
        typeIndex == typeid(TransformComponent)) registerComponent<TransformComponent>(name);
    else if(typeIndex == typeid(SpriteComponent)) registerComponent<SpriteComponent>(name);
    else if(typeIndex == typeid(RigidBodyComponent)) registerComponent<RigidBodyComponent>(name);
    else if(typeIndex == typeid(InputComponent)) registerComponent<InputComponent>(name);
  }

  return createComponent(name);
}

}
