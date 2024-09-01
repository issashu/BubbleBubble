/*
* - **Movement Input**: Stores player input for movement (e.g., direction, speed).
   - **Action Input**: Stores input for actions (e.g., jump, attack).
 */
#ifndef INPUT_H
#define INPUT_H

namespace game_core {

class InputComponent : public Component {
public:
  InputComponent();
  ~InputComponent() override;
  //TODO Finish this!
private:
  enum class InputOrigin {
    local = 0,
    network,
  };

  enum class InputType {
    keyboard = 0,
    controller
  };
};

}

#endif //INPUT_H
