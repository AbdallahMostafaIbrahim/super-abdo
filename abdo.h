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

class Abdo: public QObject, public QGraphicsItem
{
Q_OBJECT
public:
    Abdo();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void setDirection(int direction);
    int getDirection();
    GroundEntity* isGrounded();
    GroundEntity* isBlockedHorizontally(int&);
    GroundEntity* isTouchingHead();
    Coin* isTouchingCoin();
    void setState(PlayerState s);

private:
    PlayerState currentState;
    int currentFrame;
    int direction;

    QString currentUrl;
    QPixmap currentPixmap;
    QList<QPixmap> idlePixmaps;
    QList<QPixmap> runPixmaps;
    QPixmap jumpPixmap;
    QPixmap fallPixmap;
private slots:
    void animate();
};

#endif // ABDO_H
