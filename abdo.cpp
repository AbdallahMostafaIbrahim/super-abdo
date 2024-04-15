#include "abdo.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

Abdo::Abdo() {
    currentState = IDLE;
    setFlag(ItemClipsToShape);
    idlePixmaps << QPixmap(":/images/abdo/idle1.png") << QPixmap(":/images/abdo/idle2.png");
    runPixmaps << QPixmap(":/images/abdo/idle1.png") << QPixmap(":/abdo/idle2.png");
    fallPixmap = QPixmap(":/images/abdo/idle1.png");
    jumpPixmap = QPixmap(":/images/abdo/idle1.png");

    currentUrl = ":/images/abdo/idle1.png";
    direction = 1;

    currentFrame = 0;

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(450);
}

QRectF Abdo::boundingRect() const{
    return QRectF(0,0, 50, 115);
}

void Abdo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    // TODO: Fix this. I don't really know what's wrong with the animations but this makes it look a little bit better.
    int y = 0;
    if(currentState == IDLE) {
        y = currentFrame % idlePixmaps.size() == 0 ? 2 : 6;
    }
    // TODO: Optimize This
    float LtoRRatio =  (float)currentPixmap.height() / (float)currentPixmap.width();
    painter->drawPixmap(0, y, 50, 50 * LtoRRatio, direction == 1 ? currentPixmap : currentPixmap.transformed(QTransform().scale(direction,1)));

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void Abdo::setDirection(int dir) {
    direction = dir;
}

int Abdo::getDirection(){
    return direction;
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

void Abdo::setState(PlayerState state) {
    bool willAnimate = currentState != state;
    currentState = state;
    if(willAnimate) animate();
}

void Abdo::animate() {
    switch (currentState) {
        case IDLE:
            currentPixmap = (idlePixmaps[currentFrame % idlePixmaps.size()]);
            break;
        case RUNNING:
            currentPixmap = (runPixmaps[currentFrame % runPixmaps.size()]);
            break;
        case JUMPING:
            currentPixmap = (jumpPixmap);
            break;
        case FALLING:
            currentPixmap = (fallPixmap);
            break;
    }

    currentFrame++;
    update();
}
