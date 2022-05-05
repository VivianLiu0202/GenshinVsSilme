#include "shop.h"

//卡片槽

Shop::Shop()
{
    //初始化阳光值
    sun = INIT_SUN_NUM;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    Card *card = nullptr;
    for (int i = 0; i < Card::name.size(); ++i)
    {
        card = new Card(Card::name[i]);
        card->setParentItem(this);
        card->setPos(-157 + 65 * i, -2);
    }
}

QRectF Shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/images/Shop.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

//掉落阳光
void Shop::advance(int phase)
{
    if (!phase) return;
    update();
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun);
    }
}

//种植植物
void Shop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);

    foreach (QGraphicsItem *item, items)
        if (item->type() == yuanshen::Type)
            return;

    sun -= Card::cost[Card::map[s]];
    yuanshen *Yuanshen = nullptr;
    switch (Card::map[s])
    {
    case 0:
        Yuanshen = new Qiqi; break;
    case 1:
        Yuanshen = new Venti; break;
    case 2:
        Yuanshen = new Xiangling; break;
    case 3:
        Yuanshen = new Zhongli; break;
    case 4:
        Yuanshen = new Ganyu; break;
    case 5:
        Yuanshen = new Tartaglia; break;
    case 6:
        Yuanshen = new Klee; break;
    }

    //设置卡片的counter为0，重新开始冷冻
    Yuanshen->setPos(pos);
    scene()->addItem(Yuanshen);
    QList<QGraphicsItem *> child = childItems();

    foreach (QGraphicsItem *item, child)
    {
        Card *card = qgraphicsitem_cast<Card *>(item);
        if (card->text == s) card->counter = 0;
    }
    counter = 0;
}
