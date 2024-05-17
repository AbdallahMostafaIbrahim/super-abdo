#ifndef JANITOR_H
#define JANITOR_H


#include "movingenemy.h"

class Janitor : public MovingEnemy
{
    Q_OBJECT
public:
    Janitor(int, int, int, int);
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



#endif // JANITOR_H
