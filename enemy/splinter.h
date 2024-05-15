#ifndef SPLINTER_H
#define SPLINTER_H
#include "enemy/boss.h"
#include <QElapsedTimer>

class Splinter : public Boss
{
public:
    Splinter();
    void shoot() override;
private:
    QElapsedTimer bulletTimer;
    QElapsedTimer spawnTimer;

    int recoilRate;
    int newLoc;
    int slimeLoc;
};

#endif // SPLINTER_H
