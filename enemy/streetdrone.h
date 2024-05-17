#ifndef STREETDRONE_H
#define STREETDRONE_H
#include "movingenemy.h"

class StreetDrone: public MovingEnemy
{
public:
    StreetDrone(int, int, int, int);  //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QList<QPixmap> pixmaps;
    QPixmap currentPixmap;
    int currentFrame;
    int dropRate;
private slots:
    void animate() override;
};

#endif // STREETDRONE_H
