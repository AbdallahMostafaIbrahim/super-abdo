#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <QFile>
#include <QGraphicsScene>

class LevelLoader
{
public:
    LevelLoader(QFile& mapFile, QFile& enemiesFile);
    void fillScene(QGraphicsScene* scene);
private:
    void loadMap(QGraphicsScene*);
    void loadEnemies(QGraphicsScene*);
    QFile* file;
    QFile* enemiesFile;
};

#endif // LEVELLOADER_H
