#include "Actors/ActorFactory.h"
#include "Actors/Actor.h"
#include "Utils/Utils.h"

namespace game_core {

ActorsList ActorFactory::CreateActors(const json &config_file) {
  const auto numberActors = config_file["actors"].size();
  if (numberActors <= 0) {
    return std::move(m_actors);
  } // TODO Add some error message system and maybe make actors unique ptrs?
  m_actors.reserve(numberActors);

  for (auto &item : config_file["actors"].items()) {
    auto componentsCount = item.value()["components"].size();
    if (componentsCount <= 0) {
      continue;
    }

    std::unique_ptr<Actor> actor = std::make_unique<Actor>();
    actor->SetName(item.value()["name"]);
    actor->SetTag(actorTagStrings[item.value()["tag"]]);
    actor->SetStatus(EActorStatus::alive);
    for (auto &component : item.value()["components"]) {
      actor->AddComponent(GetComponentFromString(component["type"]));
    }

    m_actors.push_back(std::move(actor));
  }

  return std::move(m_actors);
}
} // namespace game_core