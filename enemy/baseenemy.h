#ifndef BASEENEMY_H
#define BASEENEMY_H

#include <QGraphicsItem>
#include <QTimer>

class BaseEnemy : public QObject, public QGraphicsItem
{
Q_OBJECT
private:
    int health;
protected:
    QTimer damageTimer;
    bool showDamage;
public:
    BaseEnemy(int initialHealth);
    virtual void move(int, int) = 0;
    void damage(int);
    int getHealth();
private slots:
    void removeDamageEffect();
};

#endif // BASEENEMY_H
