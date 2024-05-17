#ifndef ALIANDJOSHANDABDALLAH_H
#define ALIANDJOSHANDABDALLAH_H

#include <QElapsedTimer>
#include "boss.h"

class AliAndJoshAndAbdallah: public Boss
{
public:
    AliAndJoshAndAbdallah();
    void shoot() override;
private:
    QElapsedTimer bulletTimer;
    // QElapsedTimer spawnTimer;
    // QElapsedTimer slimeTimer;

    int recoilRate;
    int newLoc;
    // int slimeLoc;
    // int slimeRate;
};

#endif // ALIANDJOSHANDABDALLAH_H
