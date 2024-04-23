#ifndef BASEENEMY_H
#define BASEENEMY_H

#include <QGraphicsItem>
#include <QTimer>
#include "harmfulentity.h"

class BaseEnemy : public QObject, public QGraphicsItem, public HarmfulEntity
{
Q_OBJECT
private:
    int health;
protected:
    QTimer damageTimer;
    QTimer animationTimer;
    bool showDamage;
public:
    BaseEnemy(int initialHealth, int damage, bool animates = false);
    virtual void move(int, int) = 0;
    void damage(int);
    int getHealth();
private slots:
    void removeDamageEffect();
    virtual void animate() = 0;
};

#endif // BASEENEMY_H
