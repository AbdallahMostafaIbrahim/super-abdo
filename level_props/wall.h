#ifndef WALL_H
#define WALL_H

#include "groundentity.h"
#include <QPixmap>

class Wall: public GroundEntity
{
public:
    Wall(int w, int h);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;
    int width;
    int height;
};

#endif // WALL_H
