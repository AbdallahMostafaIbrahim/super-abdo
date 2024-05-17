#ifndef RAPHEALO_H
#define RAPHEALO_H

#include "enemy/baseenemy.h"

class Raphealo : public BaseEnemy
{
public:
    Raphealo();  //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void move(int, int) override;
private:
    QList<QPixmap> pixmaps;
    QPixmap currentPixmap;
    int currentFrame;
    int dropRate;
private slots:
    void animate() override;
};

#endif // RAPHEAL_H
