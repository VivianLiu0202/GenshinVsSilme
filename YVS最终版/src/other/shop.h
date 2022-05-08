#ifndef SHOP_H
#define SHOP_H

#include "../yuanshen/yuanshen.h"
#include "other.h"
#include "card.h"
#include "sun.h"
#include "../yuanshen/Qiqi.h"
#include "../yuanshen/Venti.h"
#include "../yuanshen/Xiangling.h"
#include "../yuanshen/ZhongLi.h"
#include "../yuanshen/Ganyu.h"
#include "../yuanshen/Tartaglia.h"
#include "../yuanshen/Klee.h"
#include "../slime/Cyro.h"

//卡片槽

class Shop : public Other
{
public:
    int sun;
    Shop();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void addPlant(QString s, QPointF pos);
private:
    int counter;
    int time;
};

#endif // SHOP_H
