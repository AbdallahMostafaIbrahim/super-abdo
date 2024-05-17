#include"pantry.h"
#include <QPainter>
#include <QRectF>


Pantry::Pantry() {

    pixmap = QPixmap(":/images/level-4/pantry.png").scaledToWidth(500);

}

void Pantry::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Pantry::boundingRect() const {
    return QRectF(0,0,pixmap.width(),pixmap.height());
}

QPainterPath Pantry::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* Pantry::getPixmap() {
    return &pixmap;
}

