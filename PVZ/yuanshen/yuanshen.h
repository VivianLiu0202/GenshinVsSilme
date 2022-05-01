#ifndef YUANSHEN_H
#define YUANSHEN_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include "../other/init.h"

//原神基类
class yuanshen : public QGraphicsItem
{
public:
    int hp;//生命值
    int state;//记录状态
    enum { Type = UserType + 1};
    yuanshen();
    ~yuanshen() override;


    QRectF boundingRect() const override;//矩形边界
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;//碰撞检测
    int type() const override;

    void setMovie(QString path);
protected:
    QMovie *movie;
    int atk;//攻击力
    int counter;//计时
    int time;//时间间隔
};
#endif // YUANSHEN_H
