#include "wall.h"
#include <QPainter>
#include <QRectF>
#include <QBrush>

Wall::Wall(int w, int h) : width(w), height(h) {
    pixmap = QPixmap(":/images/tile-1.png").scaledToWidth(100);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0, 0, width, height, pixmap);
    // for(int i = 0; i < width / pixmap.width(); i++) {
    //     for(int j = 0; j < height / pixmap.height(); j++) {
    //         painter->drawPixmap(i * pixmap.width(), j * pixmap.height(), pixmap);
    //     }
    // }

    // int remainder = 100 % width;




    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF Wall::boundingRect() const {
    return QRectF(0,0, width, height);
}

// TODO: const
QPixmap* Wall::getPixmap() {
    return &pixmap;
}
