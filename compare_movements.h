#ifndef COMPARE_MOVEMENTS_H
#define COMPARE_MOVEMENTS_H

#include "movement.h"

class compare_movements
{
public:
    bool operator() (movement &movement1, movement &movement2)
    {
        if (movement1.get_movement_weight() > movement2.get_movement_weight())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

#endif // COMPARE_MOVEMENTS_H
