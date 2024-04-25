#ifndef LEVELSETTINGS_H
#define LEVELSETTINGS_H

#include <QString>

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
};

#endif // LEVELSETTINGS_H
