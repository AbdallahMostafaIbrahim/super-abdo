#ifndef LEVELSETTINGS_H
#define LEVELSETTINGS_H

#include <QString>

// Class (we can make it a struct) that contains all level-specific settings.
class LevelSettings
{
public:
    LevelSettings();
    bool galabeyaGlideEnabled;
    bool doubleJumpEnabled;
    bool soundWaveEnabled;
    int triggerBossLoc;
    int sceneWidth;
    QString mapFile;
    QString enemiesFile;
    QString backgroundImage;
};

#endif // LEVELSETTINGS_H
