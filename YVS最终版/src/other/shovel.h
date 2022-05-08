#ifndef SHOVEL_H
#define SHOVEL_H

#include "other.h"
#include "../yuanshen/yuanshen.h"

//铲子

class Shovel : public Other
{
public:
    Shovel();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void removeYuanshen(QPointF pos);
};

#endif // SHOVEL_H
