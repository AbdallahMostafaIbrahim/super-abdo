#include "shelf.h"
#include <QPainter>
#include <QRectF>

Shelf::Shelf() {
    mainPixmap = QPixmap("");
}


QRectF Shelf::boundingRect() const {
    return QRectF(0, 0, 100, 50);
}

void Shelf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0,100, 60, mainPixmap);

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

// QPainterPath Shelf::shape() const {
//     QPainterPath path;
//     path.addRect(boundingRect());
//     return path;
// }
