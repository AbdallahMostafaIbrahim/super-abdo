#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsItem>
#include "groundentity.h"

class Platform: public GroundEntity
{
public:
    Platform(int w, int h, QPixmap pixmap);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
protected:
   QPixmap platformPixmap;
   int width, height;

};

#endif // PLATFORM_H
