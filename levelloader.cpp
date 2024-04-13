#include "levelloader.h"
#include "level_props/platform.h"
#include "level_props/desk.h"
#include "level_props/ceilinglight.h"
#include "level_props/officewindow.h"
#include "level_props/pictureframe.h"

#include <QMessageBox>
#include <QTextStream>


LevelLoader::LevelLoader(QFile& mapFile) {
    if(!mapFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(0, "Error", "Couldn't load level");
    }
    file = &mapFile;
}

void LevelLoader::fillScene(QGraphicsScene* scene) {
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
            light->setZValue(-1);
            scene->addItem(light);
        }},
        {"office_window", [scene](int x, int y) -> void {
            OfficeWindow *window = new OfficeWindow();
            window->setPos(x, (scene->height() / 2) + window->pixmap().height() / 2 + y);
            window->setZValue(-1);
            scene->addItem(window);
        }},
        {"office_picture_frame", [scene](int x, int y) -> void {
            PictureFrame *frame = new PictureFrame();
            frame->setPos(x, scene->height() / 2 + y);
            frame->setZValue(-1);
            scene->addItem(frame);
        }},
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

        bool isPlatform = type == "platform";

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
        qDebug() << type;
        if(isPlatform) {
            QPixmap p = QPixmap(platformTexture);
            p = p.scaledToHeight(height);
            Platform* platform = new Platform(width, height, p);
            platform->setPos(x, scene->height() - y - height);
            scene->addItem(platform);
        }
        else if (constructorMap.contains(type)) {
            constructorMap[type](x, y);
        } else {
            QMessageBox::warning(nullptr, "Warning", "Unknown item type: " + type);
        }
    }


    file->close();
}
