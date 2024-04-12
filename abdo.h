#ifndef ABDO_H
#define ABDO_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QRectF>

enum PlayerState {
    IDLE,
    RUNNING,
    FALLING,
    JUMPING
};

class Abdo: public QGraphicsItem
{
public:
    Abdo();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
        int direction;
private:
    PlayerState currentState;
    int currentFrame;


    QPixmap currentPixmap;

};

#endif // ABDO_H
