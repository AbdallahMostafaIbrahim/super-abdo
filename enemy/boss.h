#ifndef BOSS_H
#define BOSS_H
#include "baseenemy.h"
#include <QPixmap>

// Base Boss Class
class Boss : public BaseEnemy
{
public:
    Boss(QList<QPixmap> pixmaps, int maxHealth, int msBetweenEachFrame = 100);
    void move(int, int) override;
    virtual void shoot() = 0; // Shoot Function that will be overrided in children
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    void animate() override;
    void kill() override;
    QList<QPixmap> pixmaps;
    QList<QPainterPath> paths;
    QPixmap currentPixmap;
    QPainterPath currentPath;
    int msBetweenEachFrame;
protected:
    int currentFrame;
};

#endif // BOSS_H
