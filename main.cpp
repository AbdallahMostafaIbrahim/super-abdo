#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QFontDatabase>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Adding Splash Screen Before Showing Main Menu
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png"));
    splash->show();

    QFontDatabase::addApplicationFont(":/fonts/Minecraft.ttf");

    Game game(1280, 720);

    QTimer::singleShot(300,splash,SLOT(close()));
    QTimer::singleShot(300,&game,SLOT(show()));

    return a.exec();
}
