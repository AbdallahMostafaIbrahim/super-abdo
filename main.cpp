#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QFontDatabase>
#include "game.h"
#include "gamesaver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Adding Splash Screen Before Showing Main Menu
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png").scaledToWidth(600));
    splash->show();

    // Create Data File If it doesn't exist
    GameSaver::init();
    GameSaver::loadState();


    // Configuring Font
    QFontDatabase::addApplicationFont(":/fonts/Minecraft.ttf");

    // Creating Game Object
    Game game(1280, 720);

    // Close the Splash after 300ms and show the game view
    QTimer::singleShot(300,splash,SLOT(close()));
    QTimer::singleShot(300,&game,SLOT(show()));

    int result = a.exec();

    GameSaver::saveState();

    return result;
}
