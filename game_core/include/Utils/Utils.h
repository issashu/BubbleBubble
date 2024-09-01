#ifndef ACTORUTILS_H
#define ACTORUTILS_H
#include <unordered_map>

namespace game_core {

std::unique_ptr<Component> GetComponentFromString(const std::string& name);

}



#endif //ACTORUTILS_H
