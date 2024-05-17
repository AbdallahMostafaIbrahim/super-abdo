#include "bed.h"
#include <QPainter>
#include <QRectF>

Bed::Bed() {
    pixmap = QPixmap(":/images/level-5/bed.png").scaledToWidth(100);
}

void Bed::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Bed::boundingRect() const {
    return QRectF(0,0, pixmap.width(), pixmap.height());
}

QPainterPath Bed::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* Bed::getPixmap() {
    return &pixmap;
}
