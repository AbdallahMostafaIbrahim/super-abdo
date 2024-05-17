#ifndef SPLINTERBULLET_H
#define SPLINTERBULLET_H

#include"enemybullet.h"

class SplinterBullet : public EnemyBullet
{
public:
    SplinterBullet();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
};

#endif // SPLINTERBULLET_H
