#include "sewerpipe.h"
#include <QPainter>
#include <QRectF>

SewerPipe::SewerPipe(int w) : Platform(w, 20, QPixmap(":/images/Level 3/Sewerpipee.png").scaled(40, 40)) {
    leftPixmap = QPixmap(":/images/Level 3/Sewerpipee.png").scaled(40, 40);
    rightPixmap = QPixmap(":/images/Level 3/Sewerpipee.png").scaled(40, 40);
}


QRectF SewerPipe::boundingRect() const {
    return QRectF(0, 0, width, height);
}

void SewerPipe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
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
