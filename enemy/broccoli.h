#ifndef BROCCOLI_H
#define BROCCOLI_H
#include "enemy/boss.h"
#include <QElapsedTimer>

class Broccoli : public Boss
{
public:
    Broccoli();     //constructor
    void shoot() override;  //shoots the bullets
private:
    QElapsedTimer bulletTimer;
    QElapsedTimer spawnTimer;


    int recoilRate;
    int newLoc;
};

#endif // BROCCOLI_H
