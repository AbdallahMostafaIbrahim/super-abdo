#include "cupboard.h"
#include <QPainter>
#include <QRectF>

CupBoard::CupBoard() {
    pixmap = QPixmap(":/images/level-5/cupboard.png").scaledToWidth(100);
}

void CupBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, pixmap);
    Q_UNUSED(widget);
    Q_UNUSED(option);
}

QRectF CupBoard::boundingRect() const {
    return QRectF(0,0, pixmap.width(), pixmap.height());
}

QPainterPath CupBoard::shape() const {
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

// TODO: const
QPixmap* CupBoard::getPixmap() {
    return &pixmap;
}
