#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <QFile>
#include <QGraphicsScene>

// Utility Class to Load Levels from file
class LevelLoader
{
public:
    LevelLoader(QFile& mapFile, QFile& enemiesFile);//constructor of level loader, sets file and errors of there is a problem in files
    void fillScene(QGraphicsScene* scene);//loads enemy and map to scene
private:
    void loadMap(QGraphicsScene*);//loads map items
    void loadEnemies(QGraphicsScene*);//loads enemy items
    QFile* file;
    QFile* enemiesFile;
};

#endif // LEVELLOADER_H
