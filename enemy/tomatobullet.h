#ifndef TOMATOBULLET_H
#define TOMATOBULLET_H


#include "hagenemy.h"
#include "enemybullet.h"

class TomatoBullet : public EnemyBullet
{
public:
    TomatoBullet();  //constructor
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
};

#endif // TOMATOBULLET_H
