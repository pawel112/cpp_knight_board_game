#ifndef VALIDATION_H
#define VALIDATION_H

#include "tile.h"

class validation
{
private:
    int flag;
    int ret_val;

public:
    void orange();
    int chooser (tile *temp);
    int validate_pawn (tile *temp);
    int check (tile *temp);
};

#endif
