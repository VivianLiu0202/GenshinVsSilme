#include "slime.h"
#include "../yuanshen/yuanshen.h"
#include <QDebug>

Slime::Slime()
{
    movie = nullptr;
    hp = atk = 0;
    speed = 0.0;
    state = SlimeType::WALK;
}

Slime::~Slime()
{
    delete movie;
}

QRectF Slime::boundingRect() const
{
    return QRectF(0, -30, 90, 80);
}

void Slime::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    if (speed < 0.55 && state != SlimeType::BURN)
    {
        if (state != SlimeType::DIE) movie->setSpeed(40);
        int w = image.width();
        int h = image.height();
        for (int i = 0; i < h; ++i)
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < w - 5; ++j)
                line[j << 2] = 150;
        }
    }
    painter->drawImage(QRectF(0, -30, 90, 80), image);
}

bool Slime::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == yuanshen::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int Slime::type() const
{
    return Type;
}

void Slime::setMovie(QString path)
{
    if (movie) delete movie;
    movie = new QMovie(path);
    movie->start();
}
