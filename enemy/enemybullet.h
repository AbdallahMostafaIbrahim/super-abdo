#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "harmfulentity.h"
#include <QObject>
#include <QGraphicsItem>

class EnemyBullet : public QObject, public QGraphicsItem, public HarmfulEntity
{
    Q_OBJECT
public:
    EnemyBullet(int expiration);    //constructor
    virtual void move() = 0;
protected slots:
    void kill();    //removes the bullet from the scene after a specific condition (time or collision)
};

#endif // ENEMYBULLET_H
