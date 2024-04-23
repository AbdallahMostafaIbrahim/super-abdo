#include "enemybullet.h"
#include <QTimer>
#include <QGraphicsScene>

EnemyBullet::EnemyBullet(int expiration) : HarmfulEntity(1)
{
    QTimer::singleShot(expiration, this, SLOT(kill()));
}

void EnemyBullet::kill() {
    scene()->removeItem(this);
    delete this;
}
