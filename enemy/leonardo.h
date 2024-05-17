#ifndef LEONARDO_H
#define LEONARDO_H

#include "movingenemy.h"

class Leonardo : public MovingEnemy
{
Q_OBJECT
public:
    Leonardo(int, int, int, int);  //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    const QPixmap* getPixmap();
private:
    QList<QPixmap> frames;
    QList<QPainterPath> framesPath;
    QPixmap* currentPixmap;
    int currentFrame;
    QPainterPath currentPath;
protected slots:
    void animate() override;
};

#endif // LEONARDO_H
