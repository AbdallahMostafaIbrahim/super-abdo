#ifndef HARMFULENTITY_H
#define HARMFULENTITY_H

class HarmfulEntity
{
private:
    int damage;
    bool removeIfHit;
public:
    HarmfulEntity(int);
    int getDamage();
    void setRemovePolicy(bool);
};

#endif // HARMFULENTITY_H
