#ifndef BURNINGTRASH_H
#define BURNINGTRASH_H
#include "staticenemy.h"

class burningTrash : public StaticEnemy
{
public:
    burningTrash();
private:
    QPixmap currentPixmap;
    QList<QPixmap> pixmaps;
    int currentFrame;
private slots:
    void animate() override;
};

#endif // BURNINGTRASH_H
