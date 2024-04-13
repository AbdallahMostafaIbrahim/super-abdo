#ifndef DESK_H
#define DESK_H

#include "groundentity.h"
#include <QPixmap>

class Desk: public GroundEntity
{
public:
    Desk();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
private:
    QPixmap pixmap;
};

#endif // DESK_H
