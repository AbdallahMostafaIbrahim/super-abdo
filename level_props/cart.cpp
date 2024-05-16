#include "cart.h"
#include <QPainter>
#include <QRectF>

Cart::Cart() {

    pixmap = QPixmap(":/images/level-4/table.png").scaledToWidth(200);

}

void Cart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Cart::boundingRect() const {
    return QRectF(0,20,100, 40);
}

QPainterPath Cart::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* Cart::getPixmap() {
    return &pixmap;
}

