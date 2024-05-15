#include "scythe.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

Scythe::Scythe() : EnemyBullet(1700) {
    frames << QPixmap(":/images/Level 3/Scythe/frame_00_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_01_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_02_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_03_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_04_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_05_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_06_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_07_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_08_delay-0.1s.png").scaledToWidth(100)
           << QPixmap(":/images/Level 3/Scythe/frame_09_delay-0.1s.png").scaledToWidth(100);

    currentPixmap = &frames[0];
    currentFrame = 0;
    animationTimer.start();
}


void Scythe::move()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = &(frames[currentFrame % frames.size()]);
        currentFrame++;
        animationTimer.restart();
    }
}

void Scythe::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *currentPixmap);
}

QRectF Scythe::boundingRect() const
{
    return QRectF(0,0, currentPixmap->width(), currentPixmap->height());
}

