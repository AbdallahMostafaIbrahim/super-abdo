#include "abdo.h"
#include <QBrush>

Abdo::Abdo() {
    currentState = IDLE;
    setFlag(ItemClipsToShape);
    currentPixmap = QPixmap(":/images/mario.png");
}

QRectF Abdo::boundingRect() const{
    return QRectF(0,0,100,100);
}

void Abdo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0,100,100, currentPixmap);
    setTransformOriginPoint(boundingRect().center());
    Q_UNUSED(widget);
    Q_UNUSED(option);
}
