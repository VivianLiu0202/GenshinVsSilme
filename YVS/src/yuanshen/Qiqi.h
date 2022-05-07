#ifndef QIQI_H
#define QIQI_H

#include "yuanshen.h"
#include "../other/sun.h"

//七七奶

class Qiqi : public yuanshen
{
public:
    Qiqi();
    void advance(int phase) override;
};

#endif // QIQI_H
