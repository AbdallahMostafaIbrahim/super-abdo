#include "staticenemy.h"

StaticEnemy::StaticEnemy(QPixmap pix, int damage) : BaseEnemy(100, damage, false)
{
    pixmap = pix;
}

void StaticEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0,pixmap);
}

QRectF StaticEnemy::boundingRect() const
{
    return QRectF(0, 0, pixmap.width()-10, pixmap.height()-10);
}

void StaticEnemy::move(int, int)
{

}

const QPixmap* StaticEnemy::getPixmap()
{
    return &pixmap;
}

void StaticEnemy::animate()
{
}
