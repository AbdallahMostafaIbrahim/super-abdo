#include "raphealo.h"
#include "shuriken.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>

Raphealo::Raphealo() : BaseEnemy(100,1,true) {
    int width = 100;
    pixmaps << QPixmap(":/images/level-3/Rapheal/frame_0_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/level-3/Rapheal/frame_1_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/level-3/Rapheal/frame_2_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/level-3/Rapheal/frame_3_delay-0.1s.png").scaledToWidth(width);
    currentPixmap = pixmaps[0];
    currentFrame = 0;
    // The drop rate is a random number so that not all printers drop papers in sync.
    dropRate = QRandomGenerator::global()->bounded(10) + 9;
}

void Raphealo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
}

QRectF Raphealo::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void Raphealo::move(int, int)
{
}

void Raphealo::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        // IF currentframe is divisible by the random drop rate, we will spawn the bullet.
        if(currentFrame % dropRate == 0) {
            Shuriken* shuriken = new Shuriken();
            shuriken->setPos(x() + shuriken->boundingRect().width() / 4, y() + currentPixmap.height());
            scene()->addItem(shuriken);
        }
        animationTimer.restart();
    }
}

