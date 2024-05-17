#include "level4.h"
#include "enemy/broccoli.h"
#include "levelsettings.h"
#include "baselevel.h"
#include "game.h"
#include "enemy/karen.h"
#include "gamestate.h"
#include <QFile>

Level4::Level4(Game *game) : BaseLevel(game) {
    // Setting Level Settings

    levelSettings.triggerBossLoc = 6000;
    levelSettings.mapFile = ":/maps/map-4/map.txt";
    levelSettings.enemiesFile = ":/maps/map-4/enemies.txt";
    levelSettings.backgroundImage = ":/images/level-4/background-4.jpg";
    levelSettings.sceneWidth = 8100;
    levelSettings.sceneHeight = 2000;

    // Call Init Scene to load level using the settings
    initScene();
}

LevelSettings Level4::getLevelSettings() {
    return levelSettings;
}

Boss *Level4::newBoss()
{
    return new Broccoli;
}

int Level4::getLevelIndex()  {
    return 4;
}
