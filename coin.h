#ifndef COIN_H
#define COIN_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QRectF>

class Coin : public QGraphicsItem
{
public:
    Coin();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // COIN_H
