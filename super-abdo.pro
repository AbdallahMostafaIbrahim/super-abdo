QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abdo.cpp \
    enemy/baseenemy.cpp \
    enemy/employeeenemy.cpp \
    enemy/groundenemy.cpp \
    enemy/harmfulentity.cpp \
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
    main.cpp \
    mainmenuscene.cpp \
    soundplayer.cpp \
    utils.cpp \
    soundwave.cpp

HEADERS += \
    abdo.h \
    enemy/baseenemy.h \
    enemy/employeeenemy.h \
    enemy/groundenemy.h \
    enemy/harmfulentity.h \
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
