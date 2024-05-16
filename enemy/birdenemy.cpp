#include "birdenemy.h"
#include "birdegg.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>

BirdEnemy::BirdEnemy(): BaseEnemy(100,1,true) {
    int width = 150;
    pixmaps << QPixmap(":/images/street-bird1.gif").scaledToWidth(width) << QPixmap(":/images/street-bird2.gif").scaledToWidth(width) << QPixmap(":/images/street-bird3.gif").scaledToWidth(width) << QPixmap(":/images/street-bird4.gif").scaledToWidth(width);
    currentPixmap = pixmaps[0];
    currentFrame = 0;
    // The drop rate is a random number so that not all printers drop papers in sync.
    dropRate = QRandomGenerator::global()->bounded(3) + 6;
}

void BirdEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
}

QRectF BirdEnemy::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void BirdEnemy::move(int, int)
{
}

void BirdEnemy::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        // IF currentframe is divisible by the random drop rate, we will spawn the bullet.
        if(currentFrame % dropRate == 0) {
            BirdEgg* egg = new BirdEgg();
            egg->setPos(x() + egg->boundingRect().width() + 25, y() + currentPixmap.height());
            scene()->addItem(egg);
        }
        animationTimer.restart();
    }
}
