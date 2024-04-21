#ifndef SHOOTINGENEMY_H
#define SHOOTINGENEMY_H

#include "baseenemy.h"

template<class BulletType>
class ShootingEnemy : public BaseEnemy
{
public:
    ShootingEnemy(int initialHealth, int collisionDamage, bool animates = true);
};

#endif // SHOOTINGENEMY_H
