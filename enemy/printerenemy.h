#ifndef PRINTERENEMY_H
#define PRINTERENEMY_H
#include "baseenemy.h"

class PrinterEnemy: public BaseEnemy
{
public:
    PrinterEnemy();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void move(int, int) override;
private:
    QList<QPixmap> pixmaps;
    QPixmap currentPixmap;
    int currentFrame;
private slots:
    void animate() override;
};

#endif // PRINTERENEMY_H
