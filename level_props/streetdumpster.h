#ifndef STREETDUMPSTER_H
#define STREETDUMPSTER_H
#include "groundentity.h"
#include <QPixmap>

class StreetDumpster: public GroundEntity
{
public:
    StreetDumpster();  //constructor
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;
};

#endif // STREETDUMPSTER_H
