#ifndef KAREN_H
#define KAREN_H
#include "enemy/boss.h"
#include <QElapsedTimer>

class Karen : public Boss
{
public:
    Karen();  //constructor
    void shoot() override;  //shoots the bullets
private:
    QElapsedTimer bulletTimer;
    QElapsedTimer spawnTimer;

    int recoilRate;
    int newLoc;
};

#endif // KAREN_H
