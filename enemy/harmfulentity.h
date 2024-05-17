#ifndef HARMFULENTITY_H
#define HARMFULENTITY_H

// Anything that will damage abdo
class HarmfulEntity
{
private:
    int damage;
    bool removeIfHit;
public:
    HarmfulEntity(int);  //constructor
    int getDamage();  // returns damage done by the entity
    void setRemovePolicy(bool);  //determines if the object should be removed or not
};

#endif // HARMFULENTITY_H
