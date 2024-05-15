#ifndef SPLINTERSLIME_H
#define SPLINTERSLIME_H

#include <QElapsedTimer>
#include "enemybullet.h"

class SplinterSlime : public EnemyBullet
{
public:
    SplinterSlime();
    void move() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap* currentPixmap;
    QList<QPixmap> frames;
    int currentFrame;
    QElapsedTimer animationTimer;
};

#endif // SPLINTERSLIME_H
