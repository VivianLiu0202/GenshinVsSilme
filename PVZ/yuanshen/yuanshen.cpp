#include "yuanshen.h"
#include "../slime/slime.h"

yuanshen::yuanshen()
{
    movie = nullptr;
    atk = counter = state = time = 0;
}

yuanshen::~yuanshen()
{
    delete movie;
}

QRectF yuanshen::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void yuanshen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}

bool yuanshen::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    // 左右30像素内是否存在僵尸
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int yuanshen::type() const
{
    return Type;
}

void yuanshen::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}
