#include "shelf.h"
#include <QPainter>
#include <QRectF>

Shelf::Shelf(int w) : Platform(w, 20, QPixmap(":/images/shelf/middle.png").scaled(40, 30)) {
    leftPixmap = QPixmap(":/images/shelf/left.png").scaled(40, 30);
    rightPixmap = QPixmap(":/images/shelf/right.png").scaled(40, 30);
}

QRectF Shelf::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void Shelf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int currentX = 0;

    // Draw the left part
    painter->drawPixmap(currentX, 0, leftPixmap);
    currentX += leftPixmap.width();

    // Draw the middle parts
    int middleWidth = platformPixmap.width();
    while (currentX + middleWidth + rightPixmap.width() <= width) {
        painter->drawPixmap(currentX, 0, platformPixmap);
        currentX += middleWidth;
    }

    int spaceLeft = width - rightPixmap.width() - currentX;
    if (spaceLeft > 0) {
        painter->drawPixmap(currentX, 0,spaceLeft,platformPixmap.height(), platformPixmap);
    }

    // Draw the right part
    painter->drawPixmap(width - rightPixmap.width(), 0, rightPixmap);

    Q_UNUSED(widget);
    Q_UNUSED(option);
}
