#ifndef ELETRO_H
#define ELETRO_H

//雷元素史莱姆
#include "slime.h"
#include "../yuanshen/yuanshen.h"

class Eletro : public Slime
{
public:
    Eletro();
    void advance(int phase) override;
};

#endif // ELETRO_H
