#ifndef AI_H
#define AI_H

class movement
{
private:
    int movement_from[2];
    int movement_to[2];
    int movement_throw1[2];
    int movement_throw2[2];
    int movement_weight;

public:
    movement();
    movement (int movement_weight, int movement_from1, int movement_from2, int movement_to1, int movement_to2, int movement_throw11 = 0, int movement_throw12 = 0, int movement_throw21 = 0, int movement_throw22 = 0);
    movement (const movement &old_movement);

    int get_movement_weight() { return movement_weight; }
    int get_movement_from1() { return movement_from[0]; }
    int get_movement_from2() { return movement_from[1]; }
    int get_movement_to1() { return movement_to[0]; }
    int get_movement_to2() { return movement_to[1]; }
    int get_movement_throw11() { return movement_throw1[0]; }
    int get_movement_throw12() { return movement_throw1[1]; }
    int get_movement_throw21() { return movement_throw2[0]; }
    int get_movement_throw22() { return movement_throw2[1]; }
};
#endif
