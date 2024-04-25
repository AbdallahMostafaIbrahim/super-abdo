#ifndef KAREN_H
#define KAREN_H
#include "enemy/boss.h"
#include <QElapsedTimer>

class Karen : public Boss
{
public:
    Karen();
    void shoot() override;
private:
    QElapsedTimer bulletTimer;
    QElapsedTimer spawnTimer;

    int recoilRate;
    int newLoc;
};

#endif // KAREN_H
