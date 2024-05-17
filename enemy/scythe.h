#ifndef SCYTHE_H
#define SCYTHE_H

#include <QElapsedTimer>
#include "enemybullet.h"

class Scythe : public EnemyBullet
{
public:
    Scythe();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap* currentPixmap;
    QList<QPixmap> frames;
    int currentFrame;
    QElapsedTimer animationTimer;
};

#endif // SCYTHE_H
