#ifndef ABDO_H
#define ABDO_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QTimer>
#include "level_props/groundentity.h"
#include "level_props/coin.h"
#include "level_props/oil.h"
#include "enemy/harmfulentity.h"

enum PlayerState {
    IDLE,
    RUNNING,
    FALLING,
    JUMPING
};

// The player
class Abdo: public QObject, public QGraphicsItem
{
Q_OBJECT
public:
    Abdo();  //constructor
    // Paint Function that gets called every scene update to draw the pixmap
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;   //draws bounding rect for collision handling
    void setDirection(int direction);   //sets the direction abdo is moving in - for animation
    int getDirection();     //gets the direction abdo is moving in - for animation
    GroundEntity* isGrounded(const QList<QGraphicsItem*>&);     //determines if abdo is touching a platform from above
    GroundEntity* isBlockedHorizontally(const QList<QGraphicsItem*>&, int&);    //determines if abdo is touching a platform from the side
    GroundEntity* isTouchingHead(const QList<QGraphicsItem*>&); //determines if abdo is touching a platform from below
    Coin* isTouchingCoin(const QList<QGraphicsItem*>&); //determines if abdo is touching a coin
    Oil* isTouchingOil(const QList<QGraphicsItem*>&);   //determines if abdo is touching oil
    HarmfulEntity* isTouchingHarmfulEntity(const QList<QGraphicsItem*>&);   //determines if abdo touched a harmful entity to take damage
    void setState(PlayerState s);       //determines abdo's state
    bool takeDamage();      //determines if abdo took damage

private:
    PlayerState currentState;
    int currentFrame;
    int direction;

    QPixmap currentPixmap;
    QList<QPixmap> idlePixmaps;
    QList<QPixmap> runPixmaps;
    QPixmap jumpPixmap;
    QPixmap fallPixmap;

    QPainterPath currentPath;
    QList<QPainterPath> idlePaths;
    QList<QPainterPath> runPaths;
    QPainterPath jumpPath;
    QPainterPath fallPath;

    QTimer damageTimer;
    bool showDamage;
private slots:
    void animate();
    void removeDamageEffect();  //the temporary invincible effect gets removed after a certian time after getting damage
};

#endif // ABDO_H
