#ifndef CART_H
#define CART_H

#include "groundentity.h"
#include <QPixmap>
class Cart :public GroundEntity
{
public:
    Cart();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;


};

#endif // CART_H
