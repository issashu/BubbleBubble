/*
*    - **Position**: Stores the entity's X and Y coordinates.
   - **Rotation**: Stores the rotation angle, usually in degrees.
   - **Scale**: Stores the X and Y scaling factors.
 */
#ifndef TRANSFORM_H
#define TRANSFORM_H
namespace game_core {

class TransformComponent final : public Component {
  public:
  TransformComponent();
  ~TransformComponent() override;

  private:
    float X;
    float Y;
    enum class Facing {
      Left =0,
      Right,
      None
    };
};

};


#endif //TRANSFORM_H
