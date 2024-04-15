#ifndef SHELF_H
#define SHELF_H

#include "platform.h"
#include <QPixmap>

class Shelf : public Platform
{
public:
    Shelf(int w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
private:
    QPixmap leftPixmap;
    QPixmap rightPixmap;
};

#endif // SHELF_H
