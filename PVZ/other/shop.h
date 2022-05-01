#ifndef SHOP_H
#define SHOP_H

#include "../plant/plant.h"
#include "other.h"
#include "card.h"
#include "sun.h"
#include "../plant/Qiqi.h"
#include "../plant/Venti.h"
#include "../plant/Xiangling.h"
#include "../plant/ZhongLi.h"
#include "../plant/Ganyu.h"
#include "../plant/Dadaliya.h"
#include "../plant/Klee.h"
#include "../zombie/basiczombie.h"

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
