#include "birdegg.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

BirdEgg::BirdEgg(): EnemyBullet(10000) {
    pixmap = QPixmap(":/images/level-2/street-birdegg.png").scaledToWidth(40);
}

void BirdEgg::move()
{
    // Keeps moving down
    moveBy(0, 2);

    QList<QGraphicsItem*> items = collidingItems();

    for(QGraphicsItem* item : items) {
        if (!item) continue;

        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity) {
            return kill();
        }
    }
}

void BirdEgg::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF BirdEgg::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}
