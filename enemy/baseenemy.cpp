#include "baseenemy.h"
#include <QGraphicsScene>


BaseEnemy::BaseEnemy(int initialH, int damage, bool animates) : HarmfulEntity(damage), health(initialH), initialHealth(initialH) {
    showDamage = false;
    damageTimer.setInterval(200); // 200 milliseconds
    damageTimer.setSingleShot(true);
    animationTimer.start();
    connect(&damageTimer, SIGNAL(timeout()), this, SLOT(removeDamageEffect()));
}

void BaseEnemy::damage(int h) {
    health -= h;
    if(health <= 0) {
        kill();
    } else {
        showDamage = true;
        update();
        damageTimer.start();
    }
}

int BaseEnemy::getHealth(){
    return health;
}

int BaseEnemy::getInitialHealth() {
    return initialHealth;
}

void BaseEnemy::kill()
{
    scene()->removeItem(this);
    delete this;
}

void BaseEnemy::removeDamageEffect()
{
    showDamage = false;
    update();
}

