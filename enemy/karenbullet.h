#ifndef KARENBULLET_H
#define KARENBULLET_H

#include"enemybullet.h"

class KarenBullet : public EnemyBullet
{
public:
    KarenBullet();  //constructor
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
};

#endif // KARENBULLET_H
