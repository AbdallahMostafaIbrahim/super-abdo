#ifndef BASEENEMY_H
#define BASEENEMY_H

#include <QGraphicsItem>

class BaseEnemy : public QGraphicsItem
{
private:
    int health;
public:
    BaseEnemy(int initialHealth);
    virtual void move(int, int) = 0;
    void damage(int);
    int getHealth();
};

#endif // BASEENEMY_H
