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
* 状态state，用于记录状态
* 攻击力atk，用于造成伤害
* 速度speed，用于移动
* 动画movie，用于绘制GIF
* 动态head，用于绘制死亡僵尸头部GIF

僵尸的函数包括：

* boundingRect()，返回僵尸的边界矩形
* paint()，绘制僵尸
*
* collidesWithItem()，判定是否碰撞
* advance()，根据状态，进行碰撞检测，完成行动和状态转移
*
* setMovie()，设置动画的方便接口
*
* */

enum class SlimeType { WALK=0, ATTACK, DIE, BURN};

class Slime : public QGraphicsItem
{
public:
    int hp;
    int atk;
    qreal speed;

    //僵尸状态
    SlimeType state;

    //僵尸属于第二类（植物是第一类）
    enum { Type = UserType + 2};


    Slime();
    ~Slime() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void setMovie(QString path);
    void setHead(QString path);
protected:
    QMovie *movie;
    QMovie *head;
};


#define SLIME_ADVANCE(QSTRING1,QSTRING2,QSTRING3,QSTRING4)\
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
            setMovie(QSTRING1);\
            setHead(QSTRING2);\
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
            setMovie(QSTRING3);\
        }\
        return;\
    }\
    else\
    {\
        state = SlimeType::WALK;\
        setMovie(QSTRING4);\
    }\
    setX(x() - speed);\
}

#endif // SLIME_H
