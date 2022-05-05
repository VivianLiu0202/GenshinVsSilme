#ifndef GRASS_H
#define GRASS_H

//草元素史莱姆
#include "slime.h"
#include "../yuanshen/yuanshen.h"

class Grass : public Slime
{
public:
    Grass();
    void advance(int phase) override;
};

#endif // GRASS_H
