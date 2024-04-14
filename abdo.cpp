#include "abdo.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

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
            QRectF otherRect(item->x() + item->boundingRect().x(), item->y() + item->boundingRect().y(), item->boundingRect().width(), 5);
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
            QRectF rect(x(), y(), boundingRect().width(), boundingRect().height());
            QRectF leftRect(item->x(), item->y(), 10, item->boundingRect().height());
            if (rect.intersects(leftRect)) {
                direction = 1;
                return entity;
            }
            QRectF rightRect(item->x() + item->boundingRect().width(), item->y(), 10, item->boundingRect().height());
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

Coin* Abdo::isTouchingCoin(){
    QList<QGraphicsItem*> items = collidingItems();
    for(QGraphicsItem* item : items) {
        Coin* coin = dynamic_cast<Coin*>(item);
        if(coin != nullptr) {
            return coin;
        }
    }
    return nullptr;
}
