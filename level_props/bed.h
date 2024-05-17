#ifndef BED_H
#define BED_H

#include "groundentity.h"

class Bed : public GroundEntity
{
public:
    Bed();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;
};

#endif // BED_H
