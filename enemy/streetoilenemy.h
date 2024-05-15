#ifndef STREETOILENEMY_H
#define STREETOILENEMY_H
#include "movingenemy.h"

class StreetOilEnemy: public MovingEnemy
{
Q_OBJECT
public:
    StreetOilEnemy(int, int, int, int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    const QPixmap* getPixmap();
private:
    QPixmap idle;
    QPixmap walking;
    QPixmap* pixmap;
    QPainterPath idlePath;
    QPainterPath walkingPath;
    bool isIdle;
protected slots:
    void animate() override;
};

#endif // STREETOILENEMY_H
