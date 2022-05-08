#ifndef ATK_H
#define ATK_H

#include "other.h"
#include "../slime/slime.h"

//射手的攻击

class ATK : public Other
{
public:
    ATK(int attack = 0, ElementState flag = ElementState::SNOW);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
    ~ATK();
private:
    //元素，杀伤力，速度
    bool snow = false;
    bool water = false;
    bool fire = false;
    bool wind = false;
    int atk;
    qreal speed;
};

#endif // ATK_H
