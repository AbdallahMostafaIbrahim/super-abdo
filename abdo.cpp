#include "abdo.h"
#include <QBrush>
#include <QDebug>

Abdo::Abdo() {
    currentState = IDLE;
    setFlag(ItemClipsToShape);
    currentPixmap = QPixmap(":/images/mario.png");
    direction = 1;
}

QRectF Abdo::boundingRect() const{
    return QRectF(0,0,50,94);
}

void Abdo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, 50, 94, direction == 1 ? currentPixmap : currentPixmap.transformed(QTransform().scale(direction,1)));
    painter->drawRect(boundingRect());
    QPainterPath path;
    path.addRect(boundingRect());
    QPen pen(Qt::black, 10);
    painter->setPen(pen);
    painter->drawPath(path);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void Abdo::setDirection(int dir) {
    direction = dir;
}

