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
    void resetHealth();         //resets the health of an enemy to a predetermined number
public:
    BaseEnemy(int initialHealth, int damage, bool animates = false);        //constructor
    virtual void move(int, int) = 0;                                        //a virtual function for moving an enemy object
    void damage(int);                                                       //indicates that an enemy got damaged
    int getHealth();                                                        //returns health of an enemy
    int getInitialHealth();                                                 //returns intiial health of an enemy
    virtual void kill();                                                    //deletes an enemy if total damage exceeds health
private slots:
    void removeDamageEffect();                                              // removes the "red" color that indicates that an enemy got damaged
public slots:
    virtual void animate() = 0;                                             //virtual function that animates an enemy
};

#endif // BASEENEMY_H
