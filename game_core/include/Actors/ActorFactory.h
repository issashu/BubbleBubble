#ifndef ACTORFACTORY_H
#define ACTORFACTORY_H
#include "Managers/Singleton.h"
#include "nlohmann/json.hpp"

namespace game_core {
class Actor;
}

using json = nlohmann::ordered_json;

class ActorFactory final : public Singleton<ActorFactory> {
  friend class Singleton<ActorFactory>;

public:
  static std::unique_ptr<game_core::Actor> CreateActor();
  void CreateActors(const json& config_file);

private:
  ActorFactory() = default; //Hide for singleton consistency
  ~ActorFactory() override = default;

  static ActorFactory* m_instance;
  static std::mutex m_mutex;
  nlohmann::ordered_json m_config; //keeps insertion order https://json.nlohmann.me/api/ordered_json/
  std::vector<std::unique_ptr<game_core::Actor>> m_actors;
};



#endif //ACTORFACTORY_H
