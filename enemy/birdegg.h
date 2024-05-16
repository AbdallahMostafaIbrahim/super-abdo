#ifndef BIRDEGG_H
#define BIRDEGG_H
#include "enemybullet.h"

class BirdEgg: public EnemyBullet
{
public:
    BirdEgg();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
};

#endif // BIRDEGG_H
