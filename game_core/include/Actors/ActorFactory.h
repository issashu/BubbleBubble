// ActorFactory.h
#ifndef ACTORFACTORY_H
#define ACTORFACTORY_H

#include <vector>
#include "nlohmann/json.hpp"

namespace game_core {

class Actor;
using json = nlohmann::ordered_json;
using ActorsList = std::vector<std::unique_ptr<Actor>>;

class ActorFactory final {
public:
  static ActorFactory& GetInstance() {
    static ActorFactory instance; //TODO Read on why static local is thred-safe
    return instance;
  }

  // Delete copy constructor and assignment operator to enforce singleton property
  ActorFactory(const ActorFactory&) = delete;
  ActorFactory& operator=(const ActorFactory&) = delete;
  
  ActorsList CreateActors(const json &config_file);

private:
  ActorFactory() = default;
  ~ActorFactory() = default;

  json m_config; // keeps insertion order
  ActorsList m_actors;
};

} // namespace game_core

#endif //ACTORFACTORY_H