#include "streetcarcrash.h"
#include <QPainter>
#include <QRectF>

StreetCarCrash::StreetCarCrash() {
    pixmap = QPixmap(":/images/street-carcrash.png").scaled(400, 350);
}

void StreetCarCrash::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, 400, 350, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF StreetCarCrash::boundingRect() const {
    return QRectF(0,20,100, 50);
}

QPainterPath StreetCarCrash::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* StreetCarCrash::getPixmap() {
    return &pixmap;
}
