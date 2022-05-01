#ifndef PYRO_H
#define PYRO_H

//火元素史莱姆
#include "slime.h"
#include "../yuanshen/yuanshen.h"

class Pyro : public Slime
{
public:
    Pyro();
    void advance(int phase) override;
};

#endif // PYRO_H
