#include "tomatobullet.h"
#include "hagenemy.h"
#include "enemybullet.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

TomatoBullet::TomatoBullet() : EnemyBullet(10000) {
    pixmap = QPixmap(":/images/level-4/tomato.png").scaledToWidth(60);
}


void TomatoBullet::move()
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

void TomatoBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF TomatoBullet::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}
