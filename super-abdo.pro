QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abdo.cpp \
    basebullet.cpp \
    baselevel.cpp \
    enemy/baseenemy.cpp \
    enemy/boss.cpp \
    enemy/employeeenemy.cpp \
    enemy/enemybullet.cpp \
    enemy/harmfulentity.cpp \
    enemy/hazardsign.cpp \
    enemy/karen.cpp \
    enemy/movingenemy.cpp \
    enemy/printerbullet.cpp \
    enemy/printerenemy.cpp \
    enemy/shootingenemy.cpp \
    enemy/staticenemy.cpp \
    game.cpp \
    level1.cpp \
    level_props/ceilinglight.cpp \
    level_props/coin.cpp \
    level_props/desk.cpp \
    level_props/groundentity.cpp \
    level_props/officewindow.cpp \
    level_props/pictureframe.cpp \
    level_props/platform.cpp \
    level_props/shelf.cpp \
    levelloader.cpp \
    levelselector.cpp \
    levelsettings.cpp \
    main.cpp \
    mainmenuscene.cpp \
    soundplayer.cpp \
    utils.cpp \
    soundwave.cpp

HEADERS += \
    abdo.h \
    basebullet.h \
    baselevel.h \
    enemy/baseenemy.h \
    enemy/boss.h \
    enemy/employeeenemy.h \
    enemy/enemybullet.h \
    enemy/harmfulentity.h \
    enemy/hazardsign.h \
    enemy/karen.h \
    enemy/movingenemy.h \
    enemy/printerbullet.h \
    enemy/printerenemy.h \
    enemy/shootingenemy.h \
    enemy/staticenemy.h \
    game.h \
    level1.h \
    level_props/ceilinglight.h \
    level_props/coin.h \
    level_props/desk.h \
    level_props/groundentity.h \
    level_props/officewindow.h \
    level_props/pictureframe.h \
    level_props/platform.h \
    level_props/shelf.h \
    levelloader.h \
    levelselector.h \
    levelsettings.h \
    mainmenuscene.h \
    soundplayer.h \
    utils.h \
    soundwave.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
