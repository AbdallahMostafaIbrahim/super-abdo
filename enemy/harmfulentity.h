#ifndef HARMFULENTITY_H
#define HARMFULENTITY_H

// Anything that will damage abdo
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
