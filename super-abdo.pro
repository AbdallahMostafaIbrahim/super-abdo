QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abdo.cpp \
    baselevel.cpp \
    enemy/baseenemy.cpp \
    enemy/birdegg.cpp \
    enemy/birdenemy.cpp \
    enemy/boss.cpp \
    enemy/employeeenemy.cpp \
    enemy/enemybullet.cpp \
    enemy/harmfulentity.cpp \
    enemy/hazardsign.cpp \
    enemy/karen.cpp \
    enemy/karenbullet.cpp \
    enemy/movingenemy.cpp \
    enemy/printerbullet.cpp \
    enemy/printerenemy.cpp \
    enemy/radar.cpp \
    enemy/staticenemy.cpp \
    enemy/streetdrone.cpp \
    enemy/streetdronebullets.cpp \
    enemy/streetgarbage.cpp \
    enemy/streetoilenemy.cpp \
    enemy/streetrocks.cpp \
    enemy/vehicleenemy.cpp \
    game.cpp \
    gamestate.cpp \
    level1.cpp \
    level2.cpp \
    level_props/ceilinglight.cpp \
    level_props/coin.cpp \
    level_props/desk.cpp \
    level_props/groundentity.cpp \
    level_props/highbuilding.cpp \
    level_props/lowbuilding.cpp \
    level_props/mediumbuilding.cpp \
    level_props/officewindow.cpp \
    level_props/oil.cpp \
    level_props/pictureframe.cpp \
    level_props/platform.cpp \
    level_props/shelf.cpp \
    level_props/streetbarrier.cpp \
    level_props/streetdumpster.cpp \
    levelloader.cpp \
    levelselector.cpp \
    levelsettings.cpp \
    main.cpp \
    mainmenuscene.cpp \
    shopscene.cpp \
    soundplayer.cpp \
    utils.cpp \
    soundwave.cpp

HEADERS += \
    abdo.h \
    baselevel.h \
    enemy/baseenemy.h \
    enemy/birdegg.h \
    enemy/birdenemy.h \
    enemy/boss.h \
    enemy/employeeenemy.h \
    enemy/enemybullet.h \
    enemy/harmfulentity.h \
    enemy/hazardsign.h \
    enemy/karen.h \
    enemy/karenbullet.h \
    enemy/movingenemy.h \
    enemy/printerbullet.h \
    enemy/printerenemy.h \
    enemy/radar.h \
    enemy/staticenemy.h \
    enemy/streetdrone.h \
    enemy/streetdronebullets.h \
    enemy/streetgarbage.h \
    enemy/streetoilenemy.h \
    enemy/streetrocks.h \
    enemy/vehicleenemy.h \
    game.h \
    gamestate.h \
    level1.h \
    level2.h \
    level_props/ceilinglight.h \
    level_props/coin.h \
    level_props/desk.h \
    level_props/groundentity.h \
    level_props/highbuilding.h \
    level_props/lowbuilding.h \
    level_props/mediumbuilding.h \
    level_props/officewindow.h \
    level_props/oil.h \
    level_props/pictureframe.h \
    level_props/platform.h \
    level_props/shelf.h \
    level_props/streetbarrier.h \
    level_props/streetdumpster.h \
    levelloader.h \
    levelselector.h \
    levelsettings.h \
    mainmenuscene.h \
    shopscene.h \
    soundplayer.h \
    utils.h \
    soundwave.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
