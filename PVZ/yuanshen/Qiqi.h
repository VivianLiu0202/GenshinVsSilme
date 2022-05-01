#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"
#include "../other/sun.h"

//七七奶

class SunFlower : public Plant
{
public:
    SunFlower();
    void advance(int phase) override;
};

#endif // SUNFLOWER_H
