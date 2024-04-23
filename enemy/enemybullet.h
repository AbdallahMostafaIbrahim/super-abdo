#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "harmfulentity.h"
#include <QObject>
#include <QGraphicsItem>

class EnemyBullet : public QObject, public QGraphicsItem, public HarmfulEntity
{
    Q_OBJECT
public:
    EnemyBullet(int expiration);
    virtual void move() = 0;
protected slots:
    void kill();
};

#endif // ENEMYBULLET_H
