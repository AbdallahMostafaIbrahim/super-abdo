#include "baseenemy.h"

BaseEnemy::BaseEnemy(int initialHealth) : health(initialHealth) {
}

void BaseEnemy::damage(int h) {
    health -= h;
    if(health <= 0) {
        // TODO: Implement Death
    }
}

int BaseEnemy::getHealth(){
    return health;
}
