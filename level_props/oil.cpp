#include "oil.h"
#include <QPainter>

Oil::Oil(int w) : width(w) {
    pixmap = QPixmap(":/images/level-2/street-oilspill.png").scaledToWidth(20);
}

QRectF Oil::boundingRect() const{
    return QRectF(0,0,width,20);
}

void Oil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setOpacity(0.8);
    for(int i = 0; i < width / pixmap.width(); i++) {
        painter->drawPixmap(i * pixmap.width(), 0, pixmap);
    }


    Q_UNUSED(widget);
    Q_UNUSED(option);
}
