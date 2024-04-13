QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abdo.cpp \
    game.cpp \
    level1.cpp \
    level_props/coin.cpp \
    level_props/desk.cpp \
    level_props/groundentity.cpp \
    level_props/platform.cpp \
    level_props/shelf.cpp \
    main.cpp \
    mainmenuscene.cpp

HEADERS += \
    abdo.h \
    game.h \
    level1.h \
    level_props/coin.h \
    level_props/desk.h \
    level_props/groundentity.h \
    level_props/platform.h \
    level_props/shelf.h \
    mainmenuscene.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
