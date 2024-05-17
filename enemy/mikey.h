#ifndef MIKEY_H
#define MIKEY_H

#include "enemy/baseenemy.h"

class Mikey : public BaseEnemy
{
public:
    Mikey();  //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void move(int, int) override;
    const QPixmap* getPixmap();
private:
    QList<QPixmap> pixmaps;
    QPixmap* currentPixmap;
    int currentFrame;
    int dropRate;
private slots:
    void animate() override;
};

#endif // MIKEY_H
