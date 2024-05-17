#include "platform.h"
#include <QPainter>
#include <QRectF>
#include <QBrush>

Platform::Platform(int w, int h, QPixmap pixmap) : width(w), height(h), platformPixmap(pixmap)
{
}

QRectF Platform::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // TODO: Look at drawTiledPixmap
    if(platformPixmap.isNull()){
        return;
    }
    int count = boundingRect().width() / platformPixmap.width();
    for(int i = 0; i < count; i++) {
        painter->drawPixmap(i * platformPixmap.width(), 0, platformPixmap);
    }
    int remainder = (int)boundingRect().width() % (int)platformPixmap.width();
    if(remainder > 0) {
        painter->drawPixmap(count*platformPixmap.width(), 0, remainder, boundingRect().height(), platformPixmap);
    }

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QPainterPath Platform::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}
