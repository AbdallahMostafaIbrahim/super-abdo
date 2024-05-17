#ifndef BIRDENEMY_H
#define BIRDENEMY_H
#include "baseenemy.h"

class BirdEnemy: public BaseEnemy
{
public:
    BirdEnemy();
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

#endif // BIRDENEMY_H
