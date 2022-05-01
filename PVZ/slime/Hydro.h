#ifndef HYDRO_H
#define HYDRO_H

//水元素史莱姆
#include "slime.h"
#include "../yuanshen/yuanshen.h"

class Hydro : public Slime
{
public:
    Hydro();
    void advance(int phase) override;
};

#endif // HYDRO_H
