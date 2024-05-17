#ifndef SHURIKEN_H
#define SHURIKEN_H

#include "enemybullet.h"


class Shuriken : public EnemyBullet
{
public:
    Shuriken();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
private:
    QPixmap pixmap;
    QPainterPath* path;
};

#endif // SHURIKEN_H
