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
    enemy/boss.cpp \
    enemy/broccoli.cpp \
    enemy/employeeenemy.cpp \
    enemy/enemybullet.cpp \
    enemy/enemycart.cpp \
    enemy/hagenemy.cpp \
    enemy/harmfulentity.cpp \
    enemy/hazardsign.cpp \
    enemy/karen.cpp \
    enemy/karenbullet.cpp \
    enemy/movingenemy.cpp \
    enemy/printerbullet.cpp \
    enemy/printerenemy.cpp \
    enemy/staticenemy.cpp \
    enemy/tomatobullet.cpp \
    game.cpp \
    gamestate.cpp \
    level1.cpp \
    level4.cpp \
    level_props/cart.cpp \
    level_props/ceilinglight.cpp \
    level_props/coin.cpp \
    level_props/desk.cpp \
    level_props/groundentity.cpp \
    level_props/officewindow.cpp \
    level_props/pictureframe.cpp \
    level_props/platform.cpp \
    level_props/shelf.cpp \
    level_props/tomatoframe.cpp \
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
    enemy/boss.h \
    enemy/broccoli.h \
    enemy/employeeenemy.h \
    enemy/enemybullet.h \
    enemy/enemycart.h \
    enemy/hagenemy.h \
    enemy/harmfulentity.h \
    enemy/hazardsign.h \
    enemy/karen.h \
    enemy/karenbullet.h \
    enemy/movingenemy.h \
    enemy/printerbullet.h \
    enemy/printerenemy.h \
    enemy/staticenemy.h \
    enemy/tomatobullet.h \
    game.h \
    gamestate.h \
    level1.h \
    level4.h \
    level_props/cart.h \
    level_props/ceilinglight.h \
    level_props/coin.h \
    level_props/desk.h \
    level_props/groundentity.h \
    level_props/officewindow.h \
    level_props/pictureframe.h \
    level_props/platform.h \
    level_props/shelf.h \
    level_props/tomatoframe.h \
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
