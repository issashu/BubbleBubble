//
// Created by Issashu Greybeard on 15.08.24.
//

/*
*    - **Position**: Stores the entity's X and Y coordinates.
   - **Rotation**: Stores the rotation angle, usually in degrees.
   - **Scale**: Stores the X and Y scaling factors.
 */
#ifndef TRANSFORM_H
#define TRANSFORM_H

typedef struct Transform {
  float X;
  float Y;

  enum class Facing {
    Left =0,
    Right,
    None
  };
}TransformComponent;

#endif //TRANSFORM_H
