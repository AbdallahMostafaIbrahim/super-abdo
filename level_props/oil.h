#ifndef OIL_H
#define OIL_H
#include <QGraphicsItem>
#include <QPixmap>
#include <QRectF>

class Oil : public QGraphicsItem
{
public:
    Oil(int w);  //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPixmap pixmap;
    int width;
};

#endif // OIL_H
