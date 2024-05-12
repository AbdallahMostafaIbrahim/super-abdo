#ifndef LEONARDO_H
#define LEONARDO_H

#include "movingenemy.h"

class Leonardo : public MovingEnemy
{
Q_OBJECT
public:
    Leonardo(int, int, int, int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    const QPixmap* getPixmap();
private:
    QPixmap f0;
    QPixmap f1;
    QPixmap f2;
    QPixmap f3;
    QPixmap* pixmap;
    QPainterPath f0Path;
    QPainterPath f1Path;
    QPainterPath f2Path;
    QPainterPath f3Path;
    bool isChanged;
protected slots:
    void animate() override;
};

#endif // LEONARDO_H
