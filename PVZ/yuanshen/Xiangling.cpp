#include "Xiangling.h"

Xiangling::Xiangling()
{
    atk = atk_Xiangling;
    hp = hp_NormalYuanshen;
    setMovie(":/images/Xiangling.gif");
}

QRectF Xiangling::boundingRect() const
{
    return state ? QRectF(-150, -150, 300, 300) : yuanshen::boundingRect();
}

void Xiangling::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;

    //正常状态到爆炸状态
    else if (state == 0 && movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        state = 1;
        setMovie(":/images/Boom.gif");
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            Slime *slime = qgraphicsitem_cast<Slime *>(item);
            slime->hp -= atk;
            if (slime->hp <= 0)
            {
                slime->state = SlimeType::BURN;
                slime->setMovie(":/images/Burn.gif");
            }
        }
    }
    else if (state == 1 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

//碰撞检测：遇到僵尸 && 距离接近
bool Xiangling::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    //QLineF与QLine不同在于提供了浮点精度线段表示，
    //在成员函数方面增加了角度，单位向量等的表示，不过线段的表示法还是一样的，由两个点起点与终点标识。
    return other->type() == Slime::Type && QLineF(pos(), other->pos()).length() < 160;
}
