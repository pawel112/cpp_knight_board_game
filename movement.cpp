#include "movement.h"
#include <iostream>
#include <queue>

movement::movement()
{
    this->movement_from[0] = 0;
    this->movement_from[1] = 0;
    this->movement_to[0] = 0;
    this->movement_to[1] = 0;
    this->movement_throw1[0] = 0;
    this->movement_throw1[1] = 0;
    this->movement_throw2[0] = 0;
    this->movement_throw2[1] = 0;
    this->movement_weight = 0;
}

movement::movement (int movement_weight, int movement_from1, int movement_from2, int movement_to1, int movement_to2, int movement_throw11, int movement_throw12, int movement_throw21, int movement_throw22)
{
    this->movement_from[0] = movement_from1;
    this->movement_from[1] = movement_from2;
    this->movement_to[0] = movement_to1;
    this->movement_to[1] = movement_to2;
    this->movement_throw1[0] = movement_throw11;
    this->movement_throw1[1] = movement_throw12;
    this->movement_throw2[0] = movement_throw21;
    this->movement_throw2[1] = movement_throw22;
    this->movement_weight = movement_weight;
}

movement::movement (const movement &old_movement)
{
    movement_from[0] = old_movement.movement_from[0];
    movement_from[1] = old_movement.movement_from[1];
    movement_to[0] = old_movement.movement_to[0];
    movement_to[1] = old_movement.movement_to[1];
    movement_throw1[0] = old_movement.movement_throw1[0];
    movement_throw1[1] = old_movement.movement_throw1[1];
    movement_throw2[0] = old_movement.movement_throw2[0];
    movement_throw2[1] = old_movement.movement_throw2[1];
    movement_weight = old_movement.movement_weight;
}
