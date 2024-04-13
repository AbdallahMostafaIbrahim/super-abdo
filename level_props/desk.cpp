#include "desk.h"
#include <QPainter>
#include <QRectF>

Desk::Desk() {
    // pixmap = QPixmap(":/images/desk-1.png");
    pixmap = QPixmap(":/images/desk-1.png").scaled(100, 60);

}

void Desk::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, 100, 60, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Desk::boundingRect() const {
    return QRectF(0,20,100, 40);
}

QPainterPath Desk::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

QPixmap* Desk::getPixmap() {
    return &pixmap;
}
