#include "karen.h"
#include "karenbullet.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>

Karen::Karen() : Boss({QPixmap(":/images/boss.png")}, 20)
{

}

void Karen::shoot()
{
    if(currentFrame % 5 == 0)    {
        KarenBullet* bullet = new KarenBullet();
        bullet->setPos(x(), y() + boundingRect().height() / 2);
        scene()->addItem(bullet);
    }
}
