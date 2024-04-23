#ifndef PRINTERBULLET_H
#define PRINTERBULLET_H

#include "enemybullet.h"


class PrinterBullet : public EnemyBullet
{
public:
    PrinterBullet();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
};

#endif // PRINTERBULLET_H
