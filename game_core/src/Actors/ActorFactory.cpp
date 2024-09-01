#include "Actors/ActorFactory.h"
#include "Actors/Actor.h"
#include "Components/Component.h"
#include "Utils/Utils.h"

std::unique_ptr<game_core::Actor> ActorFactory::CreateActor() {
  // Parse the config and add components here + name the thingy + make it an
  // object to return below
  return std::make_unique<game_core::Actor>();
}

void ActorFactory::CreateActors(const json& config_file) {
  auto numberActors = config_file["actors"].size();
  if(numberActors <=0) { return; } //TODO Add some error message system
  m_actors.reserve(numberActors);

  for(auto& item : config_file["actors"].items()) {
    auto componentsCount = item.value()["components"].size();
    if(componentsCount <=0){ continue; }

    std::unique_ptr<game_core::Actor> actor{};
    actor->SetName(item.value()["name"]);
    actor->SetTag(item.value()["tag"]);
    actor->SetStatus(game_core::EActorStatus::alive);
    for(auto& component : item.value()["components"]) {
      actor->AddComponent(game_core::GetComponentFromString(component["type"]).get());
    }

    //TODO Use add component here after it's done with all the cases
  }
}