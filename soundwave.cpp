#include "soundwave.h"
#include "platform.h"
#include <QTimer>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>

SoundWave::SoundWave(int direction) : QObject()
{
    dir = direction;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
    QTimer::singleShot(1000,this,SLOT(byebye()));
}
QRectF SoundWave::boundingRect() const {
    return QRectF(0, 0, 20, 20);
}

void SoundWave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF rect = boundingRect();
    QBrush brush(Qt::black);

    painter->drawRect(rect);
    painter->fillRect(rect, brush);

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void SoundWave::move(){
        moveBy(2 * dir,0);
}

void SoundWave::byebye(){
    scene()->removeItem(this);
    delete this;
}
