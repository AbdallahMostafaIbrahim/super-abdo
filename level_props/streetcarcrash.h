#ifndef STREETCARCRASH_H
#define STREETCARCRASH_H
#include "groundentity.h"
#include <QPixmap>

class StreetCarCrash: public GroundEntity
{
public:
    StreetCarCrash();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;
};

#endif // STREETCARCRASH_H
