QT       += core gui\
            multimedia\
            multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemy/Splinterslime.cpp \
    enemy/aliandjoshandabdallah.cpp \
    enemy/baseenemy.cpp \
    enemy/boss.cpp \
    enemy/broccoli.cpp \
    enemy/burningtrash.cpp \
    enemy/employeeenemy.cpp \
    enemy/enemybullet.cpp \
    enemy/enemycart.cpp \
    enemy/hagenemy.cpp \
    enemy/harmfulentity.cpp \
    enemy/hazardsign.cpp \
    enemy/janitor.cpp \
    enemy/karen.cpp \
    enemy/karenbullet.cpp \
    enemy/leonardo.cpp \
    enemy/mikey.cpp \
    enemy/movingenemy.cpp \
    enemy/printerbullet.cpp \
    enemy/printerenemy.cpp \
    enemy/raphealo.cpp \
    enemy/scythe.cpp \
    enemy/shuriken.cpp \
    enemy/splinter.cpp \
    enemy/splinterbullet.cpp \
    enemy/staticenemy.cpp \
    enemy/tomatobullet.cpp \
    game.cpp \
    gamestate.cpp \
    level1.cpp \
    level4.cpp \
    level5.cpp \
    level_props/Table.cpp \
    level3.cpp \
    level_props/bed.cpp \
    level_props/ceilinglight.cpp \
    level_props/coin.cpp \
    level_props/cupboard.cpp \
    level_props/desk.cpp \
    level_props/groundentity.cpp \
    level_props/officewindow.cpp \
    level_props/pantry.cpp \
    level_props/pictureframe.cpp \
    level_props/platform.cpp \
    level_props/sewerpipe.cpp \
    level_props/shelf.cpp \
    level_props/tomatoframe.cpp \
    level_props/wall.cpp \
    levelloader.cpp \
    levelselector.cpp \
    levelsettings.cpp \
    main.cpp \
    mainmenuscene.cpp \
    settingsscene.cpp \
    shopscene.cpp \
    soundplayer.cpp \
    utils.cpp \
    soundwave.cpp \
    abdo.cpp \
    baselevel.cpp \
    enemy/birdegg.cpp \
    enemy/birdenemy.cpp \
    enemy/radar.cpp \
    enemy/streetdrone.cpp \
    enemy/streetdronebullets.cpp \
    enemy/streetgarbage.cpp \
    enemy/streetoilenemy.cpp \
    enemy/streetrocks.cpp \
    enemy/vehicleenemy.cpp \
    level2.cpp \
    level_props/highbuilding.cpp \
    level_props/lowbuilding.cpp \
    level_props/mediumbuilding.cpp \
    level_props/oil.cpp \
    level_props/streetbarrier.cpp \
    level_props/streetdumpster.cpp \
    gamesaver.cpp

HEADERS += \
abdo.h \
    enemy/Splinterslime.h \
    enemy/aliandjoshandabdallah.h \
    enemy/baseenemy.h \
    enemy/boss.h \
    enemy/broccoli.h \
    enemy/burningtrash.h \
    enemy/employeeenemy.h \
    enemy/enemybullet.h \
    enemy/enemycart.h \
    enemy/hagenemy.h \
    enemy/harmfulentity.h \
    enemy/hazardsign.h \
    enemy/janitor.h \
    enemy/karen.h \
    enemy/karenbullet.h \
    enemy/leonardo.h \
    enemy/mikey.h \
    enemy/movingenemy.h \
    enemy/printerbullet.h \
    enemy/printerenemy.h \
    enemy/raphealo.h \
    enemy/scythe.h \
    enemy/shuriken.h \
    enemy/splinter.h \
    enemy/splinterbullet.h \
    enemy/staticenemy.h \
    enemy/tomatobullet.h \
    game.h \
    gamestate.h \
    level1.h \
    level4.h \
    level5.h \
    level_props/Table.h \
    level3.h \
    level_props/bed.h \
    level_props/ceilinglight.h \
    level_props/coin.h \
    level_props/cupboard.h \
    level_props/desk.h \
    level_props/groundentity.h \
    level_props/officewindow.h \
    level_props/pantry.h \
    level_props/pictureframe.h \
    level_props/platform.h \
    level_props/sewerpipe.h \
    level_props/shelf.h \
    level_props/tomatoframe.h \
    level_props/wall.h \
    levelloader.h \
    levelselector.h \
    levelsettings.h \
    mainmenuscene.h \
    settingsscene.h \
    shopscene.h \
    soundplayer.h \
    utils.h \
    soundwave.h \
    abdo.h \
    baselevel.h \
    enemy/birdegg.h \
    enemy/birdenemy.h \
    enemy/radar.h \
    enemy/streetdrone.h \
    enemy/streetdronebullets.h \
    enemy/streetgarbage.h \
    enemy/streetoilenemy.h \
    enemy/streetrocks.h \
    enemy/vehicleenemy.h \
    level2.h \
    level_props/highbuilding.h \
    level_props/lowbuilding.h \
    level_props/mediumbuilding.h \
    level_props/oil.h \
    level_props/streetbarrier.h \
    level_props/streetdumpster.h \
    gamesaver.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
