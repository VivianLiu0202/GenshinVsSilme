#ifndef SLIME_H
#define SLIME_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include "../yuanshen/yuanshen.h"
#include "../other/init.h"

/* 史莱姆基类
 *
史莱姆的属性包括：

* 生命值hp，用于判定死亡
* 状态state，用于记录行动状态
* 元素状态 now 用于记录当前附着元素
* 攻击力atk，用于造成伤害
* 速度speed，用于移动
* 动画movie，用于绘制GIF

史莱姆的函数包括：

* boundingRect()，返回史莱姆的边界矩形
* paint()，绘制史莱姆
*
* collidesWithItem()，判定是否碰撞
* advance()，根据状态，进行碰撞检测，完成行动和状态转移
*
* setMovie()，设置动画的方便接口
*
* */

enum class SlimeType { WALK=0, ATTACK, DIE, BURN};

enum class ElementState { SNOW=0, WATER, FIRE, WIND, THUNDER, GRASS};

class Slime : public QGraphicsItem
{
public:
    qreal hp;
    int atk;
    qreal speed;

    //史莱姆状态
    SlimeType state;
    ElementState now;

    //史莱姆属于第二类（植物是第一类）
    enum { Type = UserType + 2};


    Slime();
    ~Slime() override;
    QRectF boundingRect() const override;
    //绘制
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    //碰撞检测
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;

    //生成的史莱姆类型
    int type() const override;

    void setMovie(QString path);
protected:
    QMovie *movie;
};

//WALK=0, ATTACK, DIE, BURN
#define SLIME_ADVANCE(QSTRING1,QSTRING2)\
{\
    if (!phase)\
        return;\
    update();\
    QList<QGraphicsItem *> items = collidingItems();\
    if (hp <= 0)\
    {\
        if (state < SlimeType::DIE)\
        {\
            state = SlimeType::DIE;\
            delete this;\
        }\
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)\
            delete this;\
        else {;}\
        return;\
    }\
    else if (!items.isEmpty())\
    {\
        yuanshen *Yuanshen = qgraphicsitem_cast<yuanshen *>(items[0]);\
        Yuanshen->hp -= atk;\
        if (state != SlimeType::ATTACK)\
        {\
            state = SlimeType::ATTACK;\
            setMovie(QSTRING2);\
        }\
        return;\
    }\
    else\
    {\
        state = SlimeType::WALK;\
        setMovie(QSTRING1);\
    }\
    setX(x() - speed);\
}

#endif // SLIME_H
