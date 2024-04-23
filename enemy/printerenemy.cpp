#include "printerenemy.h"
#include "printerbullet.h"
#include <QPainter>
#include <QGraphicsScene>

int width = 100;

PrinterEnemy::PrinterEnemy() : BaseEnemy(100,1,true) {
    pixmaps << QPixmap(":/images/printer/printer-1.png").scaledToWidth(width) << QPixmap(":/images/printer/printer-2.png").scaledToWidth(width) << QPixmap(":/images/printer/printer-3.png").scaledToWidth(width) << QPixmap(":/images/printer/printer-4.png").scaledToWidth(width);
    currentPixmap = pixmaps[0];
    currentFrame = 0;
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
    currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
    currentFrame++;

    if(currentFrame % 10 == 0) {
        PrinterBullet* bullet = new PrinterBullet();
        bullet->setPos(x() + bullet->boundingRect().width() / 4, y() + currentPixmap.height());
        scene()->addItem(bullet);
    }
}

