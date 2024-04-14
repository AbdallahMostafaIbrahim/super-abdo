#include "coin.h"
#include <QPainter>

Coin::Coin() {
    pixmap = QPixmap(":/images/coin.png");
}


QRectF Coin::boundingRect() const{
    return QRectF(0,0,40,40);
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, 40, 40, pixmap);

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
