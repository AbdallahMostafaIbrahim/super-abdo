#include "levelloader.h"
#include "level_props/platform.h"
#include "level_props/desk.h"
#include "level_props/ceilinglight.h"
#include "level_props/officewindow.h"
#include "level_props/pictureframe.h"
#include "level_props/coin.h"
#include "level_props/shelf.h"

#include "enemy/hazardsign.h"
#include "enemy/employeeenemy.h"

#include <QMessageBox>
#include <QTextStream>


LevelLoader::LevelLoader(QFile& mapFile, QFile& enemiesFile) {
    if(!mapFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(0, "Error", "Couldn't load level");
    }
    if(!enemiesFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(0, "Error", "Couldn't load enemies");
    }
    file = &mapFile;
    this->enemiesFile = &enemiesFile;
}

void LevelLoader::loadMap(QGraphicsScene* scene) {
    QTextStream stream(file);

    QMap<QString, std::function<void(int x, int y)>> constructorMap = {
        {"office_desk", [scene](int x, int y) -> void {
             Desk* desk = new Desk();
             desk->setPos(x, scene->height() - y - desk->getPixmap()->height());
             scene->addItem(desk);
         }},
        {"ceiling_light", [scene](int x, int) -> void {
             CeilingLight *light = new CeilingLight();
             light->setPos(x, 0);
             light->setZValue(-2);
             scene->addItem(light);
         }},
        {"office_window", [scene](int x, int y) -> void {
             OfficeWindow *window = new OfficeWindow();
             window->setPos(x, (scene->height() / 2) + window->pixmap().height() / 2 + y);
             window->setZValue(-2);
             scene->addItem(window);
         }},
        {"office_picture_frame", [scene](int x, int y) -> void {
             PictureFrame *frame = new PictureFrame();
             frame->setPos(x, scene->height() / 2 + y);
             frame->setZValue(-2);
             scene->addItem(frame);
         }},
        {"coin", [scene](int x, int y) -> void {
             Coin *coin = new Coin();
             coin->setPos(x, scene->height() - y - coin->boundingRect().height());
             coin->setZValue(-1);
             scene->addItem(coin);
         }}
    };

    QString line;
    int x, y, width, height;
    QString platformTexture;

    while (!stream.atEnd()) {
        line = stream.readLine().trimmed();
        if (line.isEmpty() || line.startsWith("-")) {
            continue;
        }

        QStringList parts = line.split(' ');


        if (parts.size() < 3) {
            continue;
        }

        QString type = parts[0];

        bool isPlatform = type == "platform" || type == "shelf";

        if(isPlatform && parts.size() < 6) {
            continue;
        }
        if(!isPlatform && parts.size() < 3) {
            continue;
        }

        bool ok1, ok2, ok3 = true, ok4 = true;
        x = parts[1].toInt(&ok1);
        y = parts[2].toInt(&ok2);
        width = isPlatform ? parts[3].toInt(&ok3) : 0;
        height = isPlatform ? parts[4].toInt(&ok4) : 0;
        platformTexture = isPlatform ? parts[5] : "";

        if (!(ok1 && ok2 && ok3 && ok4)) {
            QMessageBox::warning(nullptr, "Warning", "Invalid numeric values.");
            continue;
        }

        if(isPlatform) {
            if(type == "platform") {
                QPixmap p = QPixmap(platformTexture);
                p = p.scaledToHeight(height);
                Platform* platform = new Platform(width, height, p);
                platform->setPos(x, scene->height() - y - platform->boundingRect().height());
                scene->addItem(platform);
            } else {
                Shelf* shelf = new Shelf(width);
                shelf->setPos(x, scene->height() - y - shelf->boundingRect().height());
                scene->addItem(shelf);
            }
        }
        else if (constructorMap.contains(type)) {
            constructorMap[type](x, y);
        } else {
            QMessageBox::warning(nullptr, "Warning", "Unknown item type: " + type);
        }
    }


    file->close();
}

void LevelLoader::loadEnemies(QGraphicsScene* scene) {
    QTextStream stream(enemiesFile);

    QMap<QString, std::function<void(int x, int y, int left, int right, int speed)>> constructorMap = {
        {"employee", [scene](int x, int y, int left, int right, int speed) -> void {
             EmployeeEnemy* employee = new EmployeeEnemy(left, right, x, speed);
             employee->setPos(x, scene->height() - y - employee->getPixmap()->height());
             employee->setZValue(-1);
             scene->addItem(employee);
         }},

        {"hazard", [scene](int x, int y, int left, int right, int speed) -> void {
             HazardSign* hazard = new HazardSign();
             hazard->setPos(x, scene->height() - y - hazard->getPixmap()->height());
             hazard->setZValue(-1);
             scene->addItem(hazard);
         }},
    };

    QString line;
    int x, y, left, right, speed;
    while (!stream.atEnd()) {
        line = stream.readLine().trimmed();
        if (line.isEmpty() || line.startsWith("-")) {
            continue;
        }

        QStringList parts = line.split(' ');


        if (parts.size() < 6) {
            continue;
        }

        QString type = parts[0];

        bool ok1, ok2, ok3, ok4, ok5;
        x = parts[1].toInt(&ok1);
        y = parts[2].toInt(&ok2);
        left = parts[3].toInt(&ok3);
        right = parts[4].toInt(&ok4);
        speed = parts[5].toInt(&ok5);


        if (!(ok1 && ok2 && ok3 && ok4 && ok5)) {
            QMessageBox::warning(nullptr, "Warning", "Invalid numeric values.");
            continue;
        }

        if (constructorMap.contains(type)) {
            constructorMap[type](x, y, left, right, speed);
        } else {
            QMessageBox::warning(nullptr, "Warning", "Unknown item type: " + type);
        }
    }

    enemiesFile->close();
}

void LevelLoader::fillScene(QGraphicsScene* scene) {
    loadMap(scene);
    loadEnemies(scene);
}
