#ifndef CHOOSE_MOVEMENT_H
#define CHOOSE_MOVEMENT_H

#include "compare_movements.h"
#include "tile.h"
#include <queue>

class choose_movement
{
private:
    std::priority_queue <movement, std::vector <movement>, compare_movements> movements;
    std::priority_queue <movement, std::vector <movement>, compare_movements> result;

public:
    choose_movement();
    void do_movement (movement choosed_movement);
    void add_movement (movement new_movement);
    void finds_movements (tile *tile2[8][8]);
    void clear_queue();
    movement return_movement();
};

#endif // CHOOSE_MOVEMENT_H
