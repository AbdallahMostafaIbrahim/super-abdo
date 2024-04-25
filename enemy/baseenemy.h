#ifndef BASEENEMY_H
#define BASEENEMY_H

#include <QGraphicsItem>
#include <QTimer>
#include <QElapsedTimer>
#include "harmfulentity.h"

// Base Class for any enemy
class BaseEnemy : public QObject, public QGraphicsItem, public HarmfulEntity
{
Q_OBJECT
private:
    int health;
    int initialHealth;
protected:
    QTimer damageTimer;
    QElapsedTimer animationTimer;
    bool showDamage;
public:
    BaseEnemy(int initialHealth, int damage, bool animates = false);
    virtual void move(int, int) = 0;
    void damage(int);
    int getHealth();
    int getInitialHealth();
    virtual void kill();
private slots:
    void removeDamageEffect();
public slots:
    virtual void animate() = 0;
};

#endif // BASEENEMY_H
