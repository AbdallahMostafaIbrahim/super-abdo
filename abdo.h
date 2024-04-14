#ifndef ABDO_H
#define ABDO_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include "level_props/groundentity.h"
#include "level_props/coin.h"

enum PlayerState {
    IDLE,
    RUNNING,
    FALLING,
    JUMPING
};

class Abdo: public QGraphicsItem
{
public:
    Abdo();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void setDirection(int direction);
    GroundEntity* isGrounded();
    GroundEntity* isBlockedHorizontally(int&);
    GroundEntity* isTouchingHead();
    Coin* isTouchingCoin();

private:
    PlayerState currentState;
    int currentFrame;
    int direction;

    QPixmap currentPixmap;


};

#endif // ABDO_H
