#ifndef BASEBULLET_H
#define BASEBULLET_H

#include <QObject>
#include <QGraphicsObject>

class BaseBullet : public QObject, public QGraphicsItem
{
Q_OBJECT
public:
    BaseBullet(int expiration);
    virtual void move() = 0;
protected slots:
    void kill();
};

#endif // BASEBULLET_H
