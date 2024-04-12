#include "abdo.h"
#include <QBrush>
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>

Abdo::Abdo() {
    currentState = IDLE;
    setFlag(ItemClipsToShape);
    currentPixmap = QPixmap(":/images/abdo.png");
    direction = 1;
}

QRectF Abdo::boundingRect() const{
    return QRectF(0,0,50,118);
}

void Abdo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, 50, 118, direction == 1 ? currentPixmap : currentPixmap.transformed(QTransform().scale(direction,1)));

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void Abdo::setDirection(int dir) {
    direction = dir;
}

GroundEntity* Abdo::isGrounded() {
    QList<QGraphicsItem*> items = collidingItems();

    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y() + boundingRect().height() - 5, boundingRect().width(), 5);
            QRectF otherRect(item->x(), item->y(), item->boundingRect().width(), 5);
            if (rect.intersects(otherRect)) {
                return entity;
            }
        }
    }
    return nullptr;
}


GroundEntity* Abdo::isBlockedHorizontally(int& direction) {
    QList<QGraphicsItem*> items = collidingItems();
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y(), boundingRect().height(), boundingRect().width());
            QRectF leftRect(item->x(), item->y() + 1, 10, item->boundingRect().height() - 1);
            if (rect.intersects(leftRect)) {
                direction = 1;
                return entity;
            }
            QRectF rightRect(item->x() + item->boundingRect().width(), item->y() + 1, 10, item->boundingRect().height() - 1);
            if (rect.intersects(rightRect)) {
                direction = -1;
                return entity;
            }
        }
    }
    return nullptr;
}


GroundEntity* Abdo::isTouchingHead(){
    QList<QGraphicsItem*> items = collidingItems();
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y(), boundingRect().width(), 5);
            QRectF otherRect(item->x(), item->y(), item->boundingRect().width(), item->boundingRect().height());
            if (rect.intersects(otherRect)) {
                return entity;
            }
        }
    }
    return nullptr;
}
