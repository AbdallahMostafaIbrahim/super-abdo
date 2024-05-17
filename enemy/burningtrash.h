#ifndef BURNINGTRASH_H
#define BURNINGTRASH_H

#include "baseenemy.h"

class BurningTrash : public BaseEnemy
{
public:
    BurningTrash();
    QPixmap* getPixmap();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void move(int, int) override;
private:
    QPixmap* currentPixmap;
    QList<QPixmap> pixmaps;
    int currentFrame;
private slots:
    void animate() override;
};

#endif // BURNINGTRASH_H
