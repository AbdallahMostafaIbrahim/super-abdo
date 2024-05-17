#include "levelloader.h"
#include "enemy/enemycart.h"
#include "enemy/hagenemy.h"
#include "enemy/janitor.h"
#include "level_props/Table.h"
#include "level_props/pantry.h"
#include "level_props/platform.h"
#include "level_props/desk.h"
#include "level_props/ceilinglight.h"
#include "level_props/officewindow.h"
#include "level_props/pictureframe.h"
#include "level_props/coin.h"
#include "level_props/shelf.h"
#include "level_props/lowbuilding.h"
#include "level_props/mediumbuilding.h"
#include "level_props/highbuilding.h"
#include "level_props/streetbarrier.h"
#include "level_props/streetdumpster.h"
#include "level_props/oil.h"
#include "level_props/sewerpipe.h"
#include "level_props/wall.h"

#include "enemy/hazardsign.h"
#include "enemy/streetgarbage.h"
#include "enemy/employeeenemy.h"
#include "enemy/printerenemy.h"
#include "level_props/tomatoframe.h"
#include "enemy/streetoilenemy.h"
#include "enemy/vehicleenemy.h"
#include "enemy/streetrocks.h"
#include "enemy/birdenemy.h"
#include "enemy/streetdrone.h"

#include "baselevel.h"
#include "abdo.h"
#include "enemy/leonardo.h"
#include "enemy/raphealo.h"
#include "enemy/burningtrash.h"
#include "enemy/mikey.h"

#include <QMessageBox>
#include <QTextStream>

extern BaseLevel* base;

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

    // This is a map between entity name and the function called to create it.
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
         }},
        {"table", [scene](int x, int y) -> void {
             Table* table = new Table();
             table->setPos(x, scene->height() - y - table->getPixmap()->height());
             scene->addItem(table);
         }},
        {"tomato_frame", [scene](int x, int y) -> void {
             TomatoFrame *frame = new TomatoFrame();
             frame->setPos(x, scene->height() / 2 + y);
             frame->setZValue(-2);
             scene->addItem(frame);
         }},
        {"pantry", [scene](int x, int y) -> void {
             Pantry* pantry = new Pantry();
             pantry->setPos(x, scene->height() - y - pantry->getPixmap()->height());
             scene->addItem(pantry);
        }},
        {"street-lowbuilding", [scene](int x, int y) -> void {
             LowBuilding* lowbuilding = new LowBuilding();
             lowbuilding->setPos(x, scene->height() - y - lowbuilding->pixmap().height());
             lowbuilding->setZValue(-2);
             scene->addItem(lowbuilding);
         }},
        {"street-mediumbuilding", [scene](int x, int y) -> void {
             MediumBuilding* mediumbuilding = new MediumBuilding();
             mediumbuilding->setPos(x, scene->height() - y - mediumbuilding->pixmap().height());
             mediumbuilding->setZValue(-2);
             scene->addItem(mediumbuilding);
         }},
        {"street-highbuilding", [scene](int x, int y) -> void {
             HighBuilding* highbuilding = new HighBuilding();
             highbuilding->setPos(x, scene->height() - y - highbuilding->pixmap().height());
             highbuilding->setZValue(-2);
             scene->addItem(highbuilding);
         }},
        {"street-barrier", [scene](int x, int y) -> void {
             streetbarrier* barrier = new streetbarrier();
             barrier->setPos(x, scene->height() - y - barrier->getPixmap()->height());
             scene->addItem(barrier);
         }},
        {"street-dumpster", [scene](int x, int y) -> void {
             StreetDumpster *dumpster = new StreetDumpster();
             dumpster->setPos(x, scene->height() - y - dumpster->getPixmap()->height());
             scene->addItem(dumpster);
         }},
    };

    QString line;
    int x, y, width, height;
    QString platformTexture;

    // Go line by line, identify each entity, call the corresponding function to create and add the entity to the scene.
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

        bool isPlatform = type == "platform" || type == "shelf" || type == "oil" || type == "pipe" || type == "wall";

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
            } else if(type == "shelf") {
                Shelf* shelf = new Shelf(width);
                shelf->setPos(x, scene->height() - y - shelf->boundingRect().height());
                scene->addItem(shelf);
            } else if(type == "oil") {
                Oil *oil = new Oil(width);
                oil->setPos(x, scene->height() - y - oil->boundingRect().height());
                oil->setZValue(1);
                scene->addItem(oil);
            }  else if (type == "pipe"){
                SewerPipe* pipe = new SewerPipe(width);
                pipe->setPos(x, scene->height() - y - pipe->boundingRect().height());
                scene->addItem(pipe);
            } else if (type == "wall") {
                 Wall* wall = new Wall(width, height);
                 wall->setPos(x, scene->height() - y - wall->getPixmap()->height());
                 scene->addItem(wall);
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
        {"printer", [scene](int x, int y, int left, int right, int speed) -> void {
             PrinterEnemy* printer = new PrinterEnemy();
             printer->setPos(x, y);
             printer->setZValue(-1);
             scene->addItem(printer);
         }},
        {"hag", [scene](int x, int y, int left, int right, int speed) -> void {
             HagEnemy* hag = new HagEnemy();
             hag->setPos(x, y);
             hag->setZValue(-1);
             scene->addItem(hag);
         }},
        {"baby_cart", [scene](int x, int y, int left, int right, int speed) -> void {
             EnemyCart* employee = new EnemyCart(left, right, x, speed);
             employee->setPos(x, scene->height() - y - employee->getPixmap()->height());
             employee->setZValue(-1);
             scene->addItem(employee);
         }},
        {"janitor", [scene](int x, int y, int left, int right, int speed) -> void {
             Janitor* janitor = new Janitor(left, right, x, speed);
             janitor->setPos(x, scene->height() - y - janitor->getPixmap()->height());
             janitor->setZValue(-1);
             scene->addItem(janitor);
         }},
        {"garbage", [scene](int x, int y, int left, int right, int speed) -> void {
             StreetGarbage* garbage = new StreetGarbage();
             garbage->setPos(x, scene->height() - y - garbage->getPixmap()->height());
             garbage->setZValue(-1);
             scene->addItem(garbage);
         }},
        {"street-oilenemy", [scene](int x, int y, int left, int right, int speed) -> void {
             StreetOilEnemy* oilenemy = new StreetOilEnemy(left, right, x, speed);
             oilenemy->setPos(x, scene->height() - y - oilenemy->getPixmap()->height());
             oilenemy->setZValue(-1);
             scene->addItem(oilenemy);
         }},
        {"street-vehicle", [scene](int x, int y, int left, int right, int speed) -> void {
             VehicleEnemy* vehicle = new VehicleEnemy(left, right, x, speed);
             vehicle->setPos(x, scene->height() - y - vehicle->getPixmap()->height());
             vehicle->setZValue(-1);
             scene->addItem(vehicle);
         }},
        {"rocks", [scene](int x, int y, int left, int right, int speed) -> void {
             StreetRocks* rocks = new StreetRocks();
             rocks->setPos(x, scene->height() - y - rocks->getPixmap()->height());
             rocks->setZValue(-1);
             scene->addItem(rocks);
         }},
        {"bird", [scene](int x, int y, int left, int right, int speed) -> void {
             BirdEnemy* bird = new BirdEnemy();
             bird->setPos(x, y);
             bird->setZValue(-1);
             scene->addItem(bird);
         }},
        {"drone", [scene](int x, int y, int left, int right, int speed) -> void {
             StreetDrone* drone = new StreetDrone(left, right, x, speed);
             drone->setPos(x, y);
             drone->setZValue(-1);
             scene->addItem(drone);
        }},
        {"leo", [scene](int x, int y, int left, int right, int speed) -> void {
             Leonardo* leo = new Leonardo(left, right, x, speed);
             leo->setPos(x, scene->height() - y - leo->getPixmap()->height());
             leo->setZValue(-1);
             scene->addItem(leo);
         }},
        {"raph", [scene](int x, int y, int left, int right, int speed) -> void {
             Raphealo* raph = new Raphealo();
             raph->setPos(x, y);
             raph->setZValue(-1);
             scene->addItem(raph);
         }},
        {"mike", [scene](int x, int y, int left, int right, int speed) -> void {
             Mikey* mike = new Mikey();
             mike->setPos(x, scene->height() - y - mike->getPixmap()->height());
             mike->setZValue(-1);
             scene->addItem(mike);
         }},
        {"trash", [scene](int x, int y, int left, int right, int speed) -> void {
             BurningTrash* trash = new BurningTrash();
             trash->setPos(x, scene->height() - y - trash->getPixmap()->height());
             trash->setZValue(-1);
             scene->addItem(trash);
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
