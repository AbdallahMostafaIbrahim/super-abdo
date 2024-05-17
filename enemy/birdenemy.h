#ifndef BIRDENEMY_H
#define BIRDENEMY_H
#include "baseenemy.h"

class BirdEnemy: public BaseEnemy
{
public:
    BirdEnemy();    //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;    //draws the object
    QRectF boundingRect() const override;   //draws the bounding rect for collision handling
    void move(int, int) override;      //move function
private:
    QList<QPixmap> pixmaps;
    QPixmap currentPixmap;
    int currentFrame;
    int dropRate;
private slots:
    void animate() override;        //animates the object
};

#endif // BIRDENEMY_H
