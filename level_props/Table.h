#ifndef TABLE_H
#define TABLE_H

#include "groundentity.h"
#include <QPixmap>
class Table :public GroundEntity
{
public:
    Table();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;
    QPixmap* getPixmap();
private:
    QPixmap pixmap;


};

#endif // TABLE_H
