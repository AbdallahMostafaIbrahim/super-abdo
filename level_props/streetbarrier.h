#ifndef STREETBARRIER_H
#define STREETBARRIER_H
#include "groundentity.h"
#include <QPixmap>

class streetbarrier: public GroundEntity
{
public:
    streetbarrier();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;
};

#endif // STREETBARRIER_H
