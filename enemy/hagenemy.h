#ifndef HAGENEMY_H
#define HAGENEMY_H
#include "baseenemy.h"

class HagEnemy: public BaseEnemy{

public:
    HagEnemy();
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

#endif // HAGENEMY_H
