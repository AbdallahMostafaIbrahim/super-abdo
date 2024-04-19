#ifndef ABDO_H
#define ABDO_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QTimer>
#include "level_props/groundentity.h"
#include "level_props/coin.h"
#include "enemy/harmfulentity.h"

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
    GroundEntity* isGrounded(const QList<QGraphicsItem*>&);
    GroundEntity* isBlockedHorizontally(const QList<QGraphicsItem*>&, int&);
    GroundEntity* isTouchingHead(const QList<QGraphicsItem*>&);
    Coin* isTouchingCoin(const QList<QGraphicsItem*>&);
    HarmfulEntity* isTouchingHarmfulEntity(const QList<QGraphicsItem*>&);
    void setState(PlayerState s);
    bool takeDamage();

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

    QPainterPath currentPath;
    QList<QPainterPath> idlePaths;
    QList<QPainterPath> runPaths;
    QPainterPath jumpPath;
    QPainterPath fallPath;

    QTimer damageTimer;
    bool showDamage;
private slots:
    void animate();
    void removeDamageEffect();
};

#endif // ABDO_H
