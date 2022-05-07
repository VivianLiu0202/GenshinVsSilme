#ifndef ZHONGLI_H
#define ZHONGLI_H

#include "yuanshen.h"

//钟离盾

class Zhongli : public yuanshen
{
public:
    Zhongli();
    void advance(int phase) override;
};

#endif // ZHONGLI_H
