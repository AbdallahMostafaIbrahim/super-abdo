#ifndef STREETDRONEBULLETS_H
#define STREETDRONEBULLETS_H
#include "enemybullet.h"

class StreetDroneBullets: public EnemyBullet
{
public:
    StreetDroneBullets();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
};

#endif // STREETDRONEBULLETS_H
