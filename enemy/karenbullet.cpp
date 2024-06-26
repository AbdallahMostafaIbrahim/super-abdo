#include "karenbullet.h"
#include <QPainter>
#include <QRectF>

KarenBullet::KarenBullet() : EnemyBullet(6000){
    pixmap = QPixmap(":/images/printer/printer-bullet.png").scaledToWidth(60);
}

void KarenBullet::move()
{
    moveBy(-1.5, 0);
}

void KarenBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF KarenBullet::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}
