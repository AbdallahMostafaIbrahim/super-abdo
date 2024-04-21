#include "movingenemy.h"

MovingEnemy::MovingEnemy(int left, int right, int initialPos, float speed, int health, int damage, bool animates) : BaseEnemy(health, damage, animates) {
    this->left = left;
    this->right =right;
    this->initialPos = initialPos;
    this->speed = 0.05 * speed;
    this->initialTime = 0;
    // TODO : Randomize this
    this->direction = 1;
    this->offset =0;
}

void MovingEnemy::move(int elapsedTime, int delta)
{
    int currentDistance = direction * speed * (elapsedTime - initialTime) + initialPos + offset;

    if (currentDistance >= right + initialPos && direction > 0) {
        setPos(initialPos + right, y());
        initialTime = elapsedTime;
        offset = right;
        direction = direction * -1;
    } else if (currentDistance <= initialPos - left && direction < 0) {
        setPos(initialPos - left, y());
        initialTime = elapsedTime;
        offset = -left;
        direction = direction * -1;
    }
    setPos(currentDistance, y());
}
