#include "coin.h"
#include <QPainter>

Coin::Coin() {}


QRectF Coin::boundingRect() const{
    return QRectF(0,0,30,30);
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawEllipse(boundingRect());
    painter->fillRect(boundingRect(), QBrush(Qt::yellow));

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
