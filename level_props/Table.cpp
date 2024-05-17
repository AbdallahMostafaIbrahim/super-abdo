#include "table.h"
#include <QPainter>
#include <QRectF>

Table::Table() {
    pixmap = QPixmap(":/images/level-4/table.png").scaledToWidth(200);
}

void Table::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Table::boundingRect() const {
    return QRectF(15,40,pixmap.width()-30,pixmap.height());
}

QPainterPath Table::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* Table::getPixmap() {
    return &pixmap;
}

