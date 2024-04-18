#ifndef GROUNDENEMY_H
#define GROUNDENEMY_H

#include "baseenemy.h"

class GroundEnemy : public BaseEnemy
{
public:
    GroundEnemy(int left, int right, int initialPos, float speed);
    void move(int, int) override;
protected:
    int direction;
private:
    int left, right, initialPos, initialTime;
    float speed;
    int offset;
};

#endif // GROUNDENEMY_H
