#ifndef ABDO_H
#define ABDO_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include "groundentity.h"

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
    int getDirection();
    GroundEntity* isGrounded();
    GroundEntity* isBlockedHorizontally(int&);
    GroundEntity* isTouchingHead();


private:
    PlayerState currentState;
    int currentFrame;
    int direction;

    QPixmap currentPixmap;
private slots:
    void clearRect(QRectF*);

};

#endif // ABDO_H
