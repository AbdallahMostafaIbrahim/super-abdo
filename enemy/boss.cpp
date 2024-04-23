#include "boss.h"
#include <QRandomGenerator>
#include <QPainter>

Boss::Boss(QList<QPixmap> pixie, int h) : BaseEnemy(h, 1, false)
{
    int width = 250;
    pixmaps = pixie;
    currentPixmap = pixmaps[0];
    currentFrame = 0;
    dropRate = QRandomGenerator::global()->bounded(10) + 7;
}

void Boss::move(int, int)
{

}

void Boss::shoot(int)
{
    // if(currentFrame % dropRate == 0) {
    //     PrinterBullet* bullet = new PrinterBullet();
    //     bullet->setPos(x() + bullet->boundingRect().width() / 4, y() + currentPixmap.height());
    //     scene()->addItem(bullet);
    // }
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
}

QRectF Boss::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void Boss::animate()
{
    currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
    currentFrame++;

}
