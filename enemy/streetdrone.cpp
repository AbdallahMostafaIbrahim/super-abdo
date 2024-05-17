#include "streetdrone.h"
#include "streetdronebullets.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>

StreetDrone::StreetDrone(int left, int right, int initialPos, int speed): MovingEnemy(left,right,initialPos,speed,3, 1, true) {
    int width = 150;
    for(int i= 1; i<=8; i++){
        pixmaps.append(QPixmap(":/images/level-2/street-drones/street-drone" + QString::number(i) + ".png").scaledToWidth(width));
    }
    currentPixmap = pixmaps[0];
    currentFrame = 0;
    // The drop rate is a random number so that not all printers drop papers in sync.
    dropRate = QRandomGenerator::global()->bounded(6) + 4;
}

void StreetDrone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
}

QRectF StreetDrone::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}


void StreetDrone::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        // IF currentframe is divisible by the random drop rate, we will spawn the bullet.
        if(currentFrame % dropRate == 0) {
            StreetDroneBullets* bullet = new StreetDroneBullets();
            bullet->setPos(x() + bullet->boundingRect().width() + 10, y() + currentPixmap.height());
            scene()->addItem(bullet);
        }
        animationTimer.restart();
    }
}
