#include "harmfulentity.h"

HarmfulEntity::HarmfulEntity(int d) : damage(d) {
    removeIfHit = false;
}

int HarmfulEntity::getDamage()
{
    return damage;
}

void HarmfulEntity::setRemovePolicy(bool r)
{
    removeIfHit = r;
}
