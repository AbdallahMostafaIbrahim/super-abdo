#ifndef BOSS_H
#define BOSS_H
#include "baseenemy.h"
#include <QPixmap>

class Boss : public BaseEnemy
{
public:
    Boss(QList<QPixmap>, int);
    void move(int, int) override;
    virtual void shoot() = 0;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    void animate() override;
    void kill() override;
    QList<QPixmap> pixmaps;
    QList<QPainterPath> paths;
    QPixmap currentPixmap;
    QPainterPath currentPath;
protected:
    int dropRate;
    int currentFrame;
};

#endif // BOSS_H
