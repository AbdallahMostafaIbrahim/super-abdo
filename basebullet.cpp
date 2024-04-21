#include "basebullet.h"
#include <QTimer>
#include <QGraphicsScene>

BaseBullet::BaseBullet(int expiration)
{
    QTimer::singleShot(expiration, this, SLOT(kill()));
}

void BaseBullet::kill() {
    scene()->removeItem(this);
    delete this;
}
