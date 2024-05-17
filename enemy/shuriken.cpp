#include "shuriken.h"
#include "utils.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

Shuriken::Shuriken(): EnemyBullet(10000) {
    pixmap = QPixmap(":/images/level-3/shuriken.png").scaledToWidth(60);
    path = Utils::createPathFromPixmap(pixmap);
}


void Shuriken::move()
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

void Shuriken::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF Shuriken::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}

QPainterPath Shuriken::shape() const
{
    return *path;
}
