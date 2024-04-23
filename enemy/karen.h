#ifndef KAREN_H
#define KAREN_H
#include "enemy/boss.h"

class Karen : public Boss
{
public:
    Karen();
    void shoot(int) override;


};

#endif // KAREN_H
