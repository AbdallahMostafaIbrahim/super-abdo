#include "platform.h"
#include <QPainter>
#include <QRectF>

Platform::Platform(int w, int h) : width(w), height(h)
{
}

QRectF Platform::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF rect = boundingRect();
    QBrush brush(Qt::blue);

    painter->drawRect(rect);
    painter->fillRect(rect, brush);
}
