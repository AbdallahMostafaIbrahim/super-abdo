#ifndef BOSS_H
#define BOSS_H
#include "baseenemy.h"
#include <QPixmap>

// Base Boss Class
class Boss : public BaseEnemy
{
public:
    Boss(QList<QPixmap>, int);      //constructor which takes a list of pixmaps of the frames and the health as parameters
    void move(int, int) override;   //move fucntion
    virtual void shoot() = 0; // Shoot Function that will be overrided in children
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    void animate() override;
    void kill() override;       //deletes the boss when health reaches zero
    QList<QPixmap> pixmaps;
    QList<QPainterPath> paths;
    QPixmap currentPixmap;
    QPainterPath currentPath;
protected:
    int currentFrame;
};

#endif // BOSS_H
