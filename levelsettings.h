#ifndef LEVELSETTINGS_H
#define LEVELSETTINGS_H

#include <QString>

// Class (we can make it a struct) that contains all level-specific settings.
class LevelSettings
{
public:
    LevelSettings();
    // Stuff we override
    int triggerBossLoc;
    int sceneWidth;
    int sceneHeight = 720;
    QString mapFile;
    QString enemiesFile;
    QString backgroundImage;
};

#endif // LEVELSETTINGS_H
