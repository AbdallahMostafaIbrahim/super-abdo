#include "streetbarrier.h"
#include <QPainter>
#include <QRectF>

StreetBarrier::StreetBarrier() {
    pixmap = QPixmap(":/images/level-2/street-barrier.png").scaled(120, 80);
}

void StreetBarrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, 120, 80, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF StreetBarrier::boundingRect() const {
    return QRectF(0,20, 120, 80);
}

QPainterPath StreetBarrier::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* StreetBarrier::getPixmap() {
    return &pixmap;
}
