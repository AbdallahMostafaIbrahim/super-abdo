#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <QFile>
#include <QGraphicsScene>

class LevelLoader
{
public:
    LevelLoader(QFile& levelFile);
    void fillScene(QGraphicsScene* scene);
private:
    QFile* file;
};

#endif // LEVELLOADER_H
