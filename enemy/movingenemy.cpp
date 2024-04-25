#include "movingenemy.h"
#include <QRandomGenerator>

MovingEnemy::MovingEnemy(int left, int right, int initialPos, float speed, int health, int damage, bool animates) : BaseEnemy(health, damage, animates) {
    this->left = left;
    this->right = right;
    this->initialPos = initialPos;
    this->speed = speed;
    this->initialTime = 0;
    // TODO : Randomize this
    this->direction = 1;
    this->offset =0;
    startRand = QRandomGenerator::global()->bounded(1000) + 0;
}

void MovingEnemy::move(int elapsedTime, int delta)
{
    float deltaTimeSeconds = delta / 1000.0f;

    float distanceToMove = direction * speed * deltaTimeSeconds;

    float newX = x() + distanceToMove;

    if (direction == 1 && newX >= initialPos + right) {
        newX = initialPos + right;
        direction = -1;
    } else if (direction == -1 && newX <= initialPos - left) {
        newX = initialPos - left;
        direction = 1;
    }

    setPos(newX, y());
}

void MovingEnemy::animate()
{
}
