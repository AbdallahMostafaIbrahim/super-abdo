#ifndef RADAR_H
#define RADAR_H
#include "enemy/boss.h"
#include <QElapsedTimer>

class Radar: public Boss
{
public:
    Radar();
    void shoot() override;
private:
    QElapsedTimer bulletTimer;
    QElapsedTimer spawnTimer;

    int recoilRate;
    int newLoc;
};

#endif // RADAR_H
