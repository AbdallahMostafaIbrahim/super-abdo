#include "oil.h"
#include <QPainter>

Oil::Oil() {
    pixmap = QPixmap(":/images/street-oilspill.png");
}

QRectF Oil::boundingRect() const{
    return QRectF(0,0,40,40);
}

void Oil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, 40, 40, pixmap);

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
