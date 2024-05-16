#include "hagenemy.h"
#include "enemy/tomatobullet.h"


#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>


HagEnemy::HagEnemy() : BaseEnemy(100,1,true) {
    int width = 100;
    pixmaps << QPixmap(":/images/level-4/hag/hag1.png").scaledToWidth(width) << QPixmap(":/images/level-4/hag/hag2.png").scaledToWidth(width) << QPixmap(":/images/level-4/hag/hag4.png").scaledToWidth(width) << QPixmap(":/images/level-4/hag/hag3.png").scaledToWidth(width);
    currentPixmap = pixmaps[0];
    currentFrame = 0;
    // The drop rate is a random number so that not all printers drop papers in sync.
    dropRate = QRandomGenerator::global()->bounded(10) + 9;
}

void HagEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
}

QRectF HagEnemy::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void HagEnemy::move(int, int)
{
}

void HagEnemy::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        // IF currentframe is divisible by the random drop rate, we will spawn the bullet.
        if(currentFrame % dropRate == 0) {
            TomatoBullet* bullet = new TomatoBullet();
            bullet->setPos(x() + bullet->boundingRect().width() / 4, y() + currentPixmap.height());
            scene()->addItem(bullet);
        }
        animationTimer.restart();
    }
}


