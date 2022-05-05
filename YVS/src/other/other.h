#ifndef OTHER_H
#define OTHER_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

#include "init.h"

class Other : public QGraphicsItem
{
public:
    //原神第一类 敌人第二类 other第三类
    enum { Type = UserType + 3};
    Other();
    int type() const override;

};
#endif // OTHER_H
