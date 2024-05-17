#ifndef MOVINGENEMY_H
#define MOVINGENEMY_H

#include "baseenemy.h"

class MovingEnemy : public BaseEnemy
{
public:
    MovingEnemy(int left, int right, int initialPos, float speed, int health, int damage, bool animates = true);  //constructor
    void move(int, int) override;
protected:
    int direction;
    void animate() override;
private:
    int left, right, initialPos, initialTime;
    float speed;
    int offset;
    int startRand;
};

#endif // MOVINGENEMY_H
