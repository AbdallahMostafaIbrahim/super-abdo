#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsItem>

class Platform: public QGraphicsItem
{
public:
    Platform(int w, int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    int width, height;
};

#endif // PLATFORM_H
