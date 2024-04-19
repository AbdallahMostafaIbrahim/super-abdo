#include "baseenemy.h"
#include <QGraphicsScene>

BaseEnemy::BaseEnemy(int initialHealth) : health(initialHealth) {
    showDamage = false;
    damageTimer.setInterval(200); // 200 milliseconds
    damageTimer.setSingleShot(true);
    connect(&damageTimer, SIGNAL(timeout()), this, SLOT(removeDamageEffect()));
}

void BaseEnemy::damage(int h) {
    health -= h;
    if(health <= 0) {
        scene()->removeItem(this);
        delete this;
        return;
    } else {
        showDamage = true;
        update();
        damageTimer.start();
    }
}

int BaseEnemy::getHealth(){
    return health;
}

void BaseEnemy::removeDamageEffect()
{
    showDamage = false;
    update();
}
