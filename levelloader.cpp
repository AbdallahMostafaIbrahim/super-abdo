#include "levelloader.h"
#include "level_props/platform.h"
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

    QStringList entities = stream.readLine().split(" ");

    for(QString entity : entities) {
        if(entity == "platform") {
            QString line = stream.readLine();
            int x, y, w, h, tile;
            QString url;
            while(line != "-----------------------------------------") {
                QStringList data = line.split(" ");
                x = data[0].toInt();
                y = data[1].toInt();
                w = data[2].toInt();
                h = data[3].toInt();
                tile = data[4].toInt();

                // Create Current Platform
                QPixmap p = QPixmap(url);
                if(tile == 1) {
                    p = p.scaledToHeight(h);
                } else {
                    p = p.scaled(w, h);
                }
                Platform* platform = new Platform(w, h, p);
                platform->setPos(x, scene->height() - y - h);
                scene->addItem(platform);
                line = stream.readLine();
            }
        }
    }


    // file.close();
}
