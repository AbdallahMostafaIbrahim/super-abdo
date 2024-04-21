#include "printerenemy.h"
#include <QPainter>

PrinterEnemy::PrinterEnemy() : BaseEnemy(100,1,true) {
    pixmaps << QPixmap(":/images/printer/printer-1.png") << QPixmap(":/images/printer/printer-2.png")<< QPixmap(":/images/printer/printer-3.png")<< QPixmap(":/images/printer/printer-4.png");
    currentPixmap = pixmaps[0];
}

void PrinterEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
}

QRectF PrinterEnemy::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void PrinterEnemy::move(int, int)
{
}

void PrinterEnemy::animate()
{
    qDebug() << animationTimer.remainingTime();
}

