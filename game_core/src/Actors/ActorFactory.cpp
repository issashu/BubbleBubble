#include "Actors/ActorFactory.h"
#include "Actors/Actor.h"

std::unique_ptr<game_core::Actor> ActorFactory::CreateActor() {
  // Parse the config and add components here + name the thingy + make it an
  // object to return below
  return std::make_unique<game_core::Actor>();
}

void ActorFactory::ParseConfigFile(const std::string &config_file_path) {
//TODO Add logic to parse config with components here via json_lib external

}