#include "staticenemy.h"

StaticEnemy::StaticEnemy(QPixmap pix) : BaseEnemy(100, 1, false)
{
    currentPixmap = pix;
}

StaticEnemy::StaticEnemy(QList<QPixmap> frames) : BaseEnemy(100, 1, false)
{
}

void StaticEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,currentPixmap);
}

QRectF StaticEnemy::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width()-10, currentPixmap.height()-10);
}

void StaticEnemy::move(int, int)
{

}

const QPixmap* StaticEnemy::getPixmap()
{
    return &currentPixmap;
}

void StaticEnemy::animate()
{
}
