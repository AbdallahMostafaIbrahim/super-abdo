#include "streetdronebullets.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

StreetDroneBullets::StreetDroneBullets(): EnemyBullet(10000) {
    pixmap = QPixmap(":/images/level-2/drone-bullet.png").scaledToWidth(40);
}

void StreetDroneBullets::move()
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

void StreetDroneBullets::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF StreetDroneBullets::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}
