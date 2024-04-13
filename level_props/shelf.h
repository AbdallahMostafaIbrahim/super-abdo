#ifndef SHELF_H
#define SHELF_H

#include "groundentity.h"
#include <QPixmap>

class Shelf : public GroundEntity
{
public:
    Shelf();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    // QPainterPath shape() const override;
private:
    QPixmap mainPixmap;
    QPixmap edgePixmap;

};

#endif // SHELF_H
