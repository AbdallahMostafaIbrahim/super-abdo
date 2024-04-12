#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Adding Splash Screen Before Showing Main Menu
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/supermariosplash.png"));
    splash->show();

    Game game(1280, 720);

    // this->move(x, y);


    QTimer::singleShot(300,splash,SLOT(close()));
    QTimer::singleShot(300,&game,SLOT(show()));

    return a.exec();
}
