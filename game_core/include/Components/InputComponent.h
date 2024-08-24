/*
* - **Movement Input**: Stores player input for movement (e.g., direction, speed).
   - **Action Input**: Stores input for actions (e.g., jump, attack).
 */
#ifndef INPUT_H
#define INPUT_H

enum class InputOrigin {
  local = 0,
  network,
};

enum class InputType {
  keyboard = 0,
  controller
};

#endif //INPUT_H
