#include "streetdumpster.h"
#include <QPainter>
#include <QRectF>

StreetDumpster::StreetDumpster() {
    pixmap = QPixmap(":/images/street-dumpster.png").scaledToWidth(150);
}

void StreetDumpster::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF StreetDumpster::boundingRect() const {
    return QRectF(0,0, pixmap.width(), pixmap.height());
}

QPainterPath StreetDumpster::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* StreetDumpster::getPixmap() {
    return &pixmap;
}
