#ifndef ANEMO_H
#define ANEMO_H

//风元素史莱姆
#include "slime.h"
#include "../yuanshen/yuanshen.h"

class Anemo : public Slime
{
public:
    Anemo();
    void advance(int phase) override;
};

#endif // ANEMO_H
