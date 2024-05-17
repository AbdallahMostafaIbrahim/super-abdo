#ifndef PANTRY_H
#define PANTRY_H





#include "groundentity.h"
#include <QPixmap>
class Pantry :public GroundEntity
{
public:
    Pantry();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;


};

#endif // PANTRY_H
