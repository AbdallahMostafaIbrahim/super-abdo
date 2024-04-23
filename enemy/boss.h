#ifndef BOSS_H
#define BOSS_H
#include "baseenemy.h"
#include <QPixmap>

class Boss : public BaseEnemy
{
public:
    Boss(QList<QPixmap>, int);
    void move(int, int) override;
    virtual void shoot(int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    void animate() override;
    QList<QPixmap> pixmaps;
    QPixmap currentPixmap;
    int currentFrame;
protected:
    int dropRate;
};

#endif // BOSS_H
