#include "printerenemy.h"
#include "printerbullet.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>


PrinterEnemy::PrinterEnemy() : BaseEnemy(100,1,true) {
    int width = 100;
    pixmaps << QPixmap(":/images/printer/printer-1.png").scaledToWidth(width) << QPixmap(":/images/printer/printer-2.png").scaledToWidth(width) << QPixmap(":/images/printer/printer-3.png").scaledToWidth(width) << QPixmap(":/images/printer/printer-4.png").scaledToWidth(width);
    currentPixmap = pixmaps[0];
    currentFrame = 0;
    dropRate = QRandomGenerator::global()->bounded(10) + 9;

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
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        if(currentFrame % dropRate == 0) {
            PrinterBullet* bullet = new PrinterBullet();
            bullet->setPos(x() + bullet->boundingRect().width() / 4, y() + currentPixmap.height());
            scene()->addItem(bullet);
        }
        animationTimer.restart();
    }
}

