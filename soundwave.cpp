#include "soundwave.h"
#include "platform.h"
#include <QTimer>
#include<QPainter>
#include<QGraphicsItem>
#include<QGraphicsScene>

SoundWave::SoundWave(int direction) : QObject()
{
    pixmap = QPixmap(":/images/sound-wave.png");

    dir = direction;
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(5);
    QTimer::singleShot(1000,this,SLOT(byebye()));
}
QRectF SoundWave::boundingRect() const {
    return QRectF(0, 0, 40, 40);
}

void SoundWave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, 40, 40, dir == 1 ? pixmap : pixmap.transformed(QTransform().scale(dir,1)));

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void SoundWave::move(){
    moveBy(2 * dir,0);

    QList<QGraphicsItem*> items = collidingItems();

    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            return byebye();
        }
    }
}

void SoundWave::byebye(){
    scene()->removeItem(this);
    delete this;
}
