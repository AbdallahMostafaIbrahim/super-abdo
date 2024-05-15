#include "Splinterslime.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

SplinterSlime::SplinterSlime() : EnemyBullet(1700) {
    frames << QPixmap(":/images/Level 3/slime/frame_02_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_03_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_04_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_05_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_06_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_07_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_08_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_09_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_10_delay-0.1s.png").scaledToWidth(60)
           << QPixmap(":/images/Level 3/slime/frame_11_delay-0.1s.png").scaledToWidth(60);

    currentPixmap = &frames[0];
    currentFrame = 0;
    animationTimer.start();
}



void SplinterSlime::move()
{
    // Keeps moving down
    moveBy(0, 2);

    if(animationTimer.elapsed() >= 300) {
        currentPixmap = &(frames[currentFrame % frames.size()]);
        currentFrame++;
        animationTimer.restart();
    }


    QList<QGraphicsItem*> items = collidingItems();

    for(QGraphicsItem* item : items) {
        if (!item) continue;

        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity) {
            return kill();
        }
    }
}

void SplinterSlime::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *currentPixmap);
}

QRectF SplinterSlime::boundingRect() const
{
    return QRectF(0,0, currentPixmap->width(), currentPixmap->height());
}

