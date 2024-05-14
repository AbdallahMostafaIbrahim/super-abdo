#include "splinterbullet.h"
#include <QPainter>
#include <QRectF>

SplinterBullet::SplinterBullet(): EnemyBullet(6000){
    pixmap = QPixmap(":/images/Level 3/pizza.png").scaledToWidth(60);
}


void SplinterBullet::move()
{
    moveBy(-1.5, 0);
}

void SplinterBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF SplinterBullet::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}
