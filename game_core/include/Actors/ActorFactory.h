#ifndef ACTORFACTORY_H
#define ACTORFACTORY_H
#include "Managers/Singleton.h"
#include "nlohmann/json.hpp"

namespace game_core {
class Actor;
}

class ActorFactory final : public Singleton<ActorFactory> {
  friend class Singleton<ActorFactory>;

public:
  static std::unique_ptr<game_core::Actor> CreateActor();
  void ParseConfigFile(const std::string& config_file_path);

private:
  ActorFactory() = default; //Hide for singleton consistency
  ~ActorFactory() override = default;

  static ActorFactory* m_instance;
  static std::mutex m_mutex;
  nlohmann::ordered_json m_config; //keeps insertion order https://json.nlohmann.me/api/ordered_json/
};



#endif //ACTORFACTORY_H
