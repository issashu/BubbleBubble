#include <string>
#include <any>

#include "Components/Component.h"
#include "Utils/Utils.h"

#include "Components/Controllers/PlayerController.h"
#include "Components/RigidBodyComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/TransformComponent.h"
#include "nlohmann/json.hpp"

#include <functional>
#include <sstream>
#include <typeindex>

namespace game_core {
using ComponentCreator = std::function<std::unique_ptr<Component>()>;

std::unordered_map<std::string, ComponentCreator> componentFactory;
std::unordered_map<std::string, std::any> actorComponents = { //TODO Check do we really need any, considering we have type_index everywhere
  {"Transform" , std::type_index(typeid(TransformComponent))},
  {"Sprite", std::type_index(typeid(SpriteComponent))},
  {"Body", std::type_index(typeid(RigidBodyComponent))},
  {"PlayerInput", std::type_index(typeid(PlayerController))},
};

template<typename T>
    void registerComponent(const std::string& typeName) {
  componentFactory[typeName] = []() -> std::unique_ptr<Component> {
    return std::make_unique<T>();
  };
}

std::unique_ptr<Component> createComponent(const std::string& typeName) {
  if (const auto it = componentFactory.find(typeName); it != componentFactory.end()) {
    return it->second();
  }
  return nullptr;
}


std::unique_ptr<Component> GetComponentFromString(const std::string& name) {
  // Get component from map or create a new entry first, if it is not found/hasn't been used before
  if (const auto it = componentFactory.find(name); it == componentFactory.end()) {
    if (const auto typeIndex = std::any_cast<std::type_index>(actorComponents[name]);
        typeIndex == typeid(TransformComponent))
    {
      registerComponent<TransformComponent>(name);
    }
    else if(typeIndex == typeid(SpriteComponent))
    {
      registerComponent<SpriteComponent>(name);
    }
    else if(typeIndex == typeid(RigidBodyComponent))
    {
      registerComponent<RigidBodyComponent>(name);
    }
    else if(typeIndex == typeid(PlayerController))
    {
      registerComponent<PlayerController>(name);
    }
  }

  return createComponent(name);
}

/**
 * Splits the given input string into parts based on the specified delimiter.
 *
 * @param input The string to be split.
 * @param delimiter The character or substring used as the delimiter.
 * @return A vector of strings, each of which is a part of the original string
 * separated by the delimiter.
 */
std::vector<std::string> splitString(const std::string& string, char delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(string);
  while (std::getline(tokenStream, token, delimiter)) {
    tokens.push_back(token);
  }
  return tokens;
}

}
