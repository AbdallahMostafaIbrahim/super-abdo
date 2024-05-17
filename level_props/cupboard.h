#ifndef CUPBOARD_H
#define CUPBOARD_H

#include "groundentity.h"

class CupBoard : public GroundEntity
{
public:
    CupBoard();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;
};

#endif // CUPBOARD_H
