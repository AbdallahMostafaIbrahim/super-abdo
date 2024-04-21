#include "shootingenemy.h"

template<class BulletType>
ShootingEnemy<BulletType>::ShootingEnemy(int initialHealth, int collisionDamage, bool animates) : BaseEnemy(initialHealth, collisionDamage)
{
    if(animates) {
        QTimer* timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
        timer->start(320);
    }
}
