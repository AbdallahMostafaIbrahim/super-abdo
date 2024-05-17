#ifndef BIRDEGG_H
#define BIRDEGG_H
#include "enemybullet.h"

class BirdEgg: public EnemyBullet
{
public:
    BirdEgg();      //constructor
    void move() override;       // vertical movement function
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;    //draws the object
    QRectF boundingRect() const override;       //draws a bounding rect that collides with any entity
private:
    QPixmap pixmap;
};

#endif // BIRDEGG_H
