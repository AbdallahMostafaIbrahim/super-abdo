#ifndef SEWERPIPE_H
#define SEWERPIPE_H

#include "platform.h"
#include <QPixmap>

class SewerPipe : public Platform
{
public:
    SewerPipe(int w);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
private:
    QPixmap leftPixmap;
    QPixmap rightPixmap;
};

#endif // SEWERPIPE_H
