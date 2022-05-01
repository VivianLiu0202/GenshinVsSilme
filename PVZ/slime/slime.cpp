#include "slime.h"
#include "../yuanshen/yuanshen.h"
#include <QDebug>

Slime::Slime()
{
    movie = head = nullptr;
    hp = atk = 0;
    speed = 0.0;
    state = SlimeType::WALK;
}

Slime::~Slime()
{
    delete movie;
    delete head;
}

QRectF Slime::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void Slime::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    if (speed < 0.55 && state != SlimeType::BURN)
    {
        if (state != SlimeType::DIE)
            movie->setSpeed(50);
        int w = image.width();
        int h = image.height();
        for (int i = 0; i < h; ++i)
        {
            uchar *line = image.scanLine(i);
            for (int j = 5; j < w - 5; ++j)
                line[j << 2] = 200;
        }
    }
    painter->drawImage(QRectF(-70, -100, 140, 140), image);
    if (head)
    {
        image = head->currentImage();
        if (speed < 0.55)
        {
            int w = image.width();
            int h = image.height();
            for (int i = 0; i < h; ++i)
            {
                uchar *line = image.scanLine(i);
                for (int j = 5; j < w - 5; ++j)
                    line[j << 2] = 200;
            }
        }
        painter->drawImage(QRectF(0, -100, 140, 140), image);
    }
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

void Slime::setHead(QString path)
{
    if (head)
        delete head;
    head = new QMovie(path);
    head->start();
}
