#include "button.h"

//按钮操作:控制游戏暂停和继续的按钮，需要重写鼠标按下事件。

Button::Button(QSound *s, QTimer *t)
{
    sound = s;
    timer = t;
}

//返回 按钮 所在的矩形区域
QRectF Button::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
    //建立矩形坐标
}

//绘制按钮，根据是否点击按钮 绘制 “pause” 或者 “continue”
void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    //设置按钮图片
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/images/Button.png"));
    painter->setPen(Qt::green);

    //设置文本格式
    QFont font("Calibri", 18, QFont::Bold, true);
    painter->setFont(font);

    if (timer->isActive())
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE!");
    else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE!");
}

//鼠标左键点击事件
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            sound->stop();
            timer->stop();
        }
        else
        {
            sound->play();
            timer->start();
        }
    }
    update();
}
