#include "printerbullet.h"
#include "level_props/groundentity.h"
#include <QPainter>
#include <QRectF>

PrinterBullet::PrinterBullet() : EnemyBullet(10000) {
    pixmap = QPixmap(":/images/printer/printer-bullet.png").scaledToWidth(60);
}


void PrinterBullet::move()
{
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

void PrinterBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, pixmap);
}

QRectF PrinterBullet::boundingRect() const
{
    return QRectF(0,0, pixmap.width(), pixmap.height());
}
