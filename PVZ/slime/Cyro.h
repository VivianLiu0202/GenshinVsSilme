#ifndef CYRO_H
#define CYRO_H

//冰元素史莱姆
#include "slime.h"
#include "../yuanshen/yuanshen.h"

class Cyro : public Slime
{
public:
    Cyro();
    void advance(int phase) override;
};

#endif // CYRO_H
