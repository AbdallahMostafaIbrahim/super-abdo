#include "burningtrash.h"
#include <QPainter>

BurningTrash::BurningTrash() : BaseEnemy(100, 1, true) {
    int width = 100;
    pixmaps << QPixmap(":/images/level-3/trash/frame_0_delay-0.07s.png").scaledToWidth(width)
            << QPixmap(":/images/level-3/trash/frame_1_delay-0.07s.png").scaledToWidth(width)
            << QPixmap(":/images/level-3/trash/frame_1_delay-0.07s.png").scaledToWidth(width)
            << QPixmap(":/images/level-3/trash/frame_1_delay-0.07s.png").scaledToWidth(width);
    currentPixmap = &pixmaps[0];
    currentFrame = 0;
}

QPixmap *BurningTrash::getPixmap()
{
    return currentPixmap;
}

void BurningTrash::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *currentPixmap);

}

QRectF BurningTrash::boundingRect() const
{
    return QRectF(30, 10, currentPixmap->width() - 60, currentPixmap->height() - 20);
}

void BurningTrash::move(int, int)
{

}

void BurningTrash::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = &(pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        animationTimer.restart();
    }
}
