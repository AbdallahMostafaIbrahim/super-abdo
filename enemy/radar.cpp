#include "radar.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "vehicleenemy.h"

Radar::Radar(): Boss({QPixmap(":/images/level-2/radar.png").scaledToWidth(120)}, 25)
{
    bulletTimer.start();
    spawnTimer.start();
    recoilRate = QRandomGenerator::global()->bounded(1500) + 700;
    newLoc = QRandomGenerator::global()->bounded(12) + 9;
}

void Radar::shoot()
{
    if (spawnTimer.elapsed() >=7000){
        VehicleEnemy * car = new VehicleEnemy(2000, 0, x(), 300);
        car->setPos(x(), boundingRect().height() + y() - car->boundingRect().height());
        scene()->addItem(car);
        spawnTimer.restart();
    }
}
