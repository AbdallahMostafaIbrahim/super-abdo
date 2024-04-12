#include "platform.h"
#include <QPainter>
#include <QRectF>

Platform::Platform(int w, int h, QPixmap pixmap) : width(w), height(h)
{
    this->pixmap = pixmap;
}

QRectF Platform::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int count = boundingRect().width() / pixmap.width();
    for(int i = 0; i < count; i++) {
        painter->drawPixmap(i * pixmap.width(), 0, pixmap);
    }
    int remainder = (int)boundingRect().width() % (int)pixmap.width();
    if(remainder > 0) {
        painter->drawPixmap(count*pixmap.width(), 0, remainder, boundingRect().height(), pixmap);
    }

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
