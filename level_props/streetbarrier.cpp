#include "streetbarrier.h"
#include <QPainter>
#include <QRectF>

streetbarrier::streetbarrier() {

    pixmap = QPixmap(":/images/street-barrier.png").scaled(120, 80);
}

void streetbarrier::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, 120, 80, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF streetbarrier::boundingRect() const {
    return QRectF(0,20, 120, 80);
}

QPainterPath streetbarrier::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* streetbarrier::getPixmap() {
    return &pixmap;
}
