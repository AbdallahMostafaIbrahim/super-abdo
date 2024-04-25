#include "karen.h"
#include "karenbullet.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "employeeenemy.h"

Karen::Karen() : Boss({QPixmap(":/images/boss.png")}, 30)
{
    bulletTimer.start();
    spawnTimer.start();
    recoilRate = QRandomGenerator::global()->bounded(1500) + 700;
    newLoc = QRandomGenerator::global()->bounded(12) + 9;
}

void Karen::shoot()
{
    if(bulletTimer.elapsed() > recoilRate)    {
        recoilRate = QRandomGenerator::global()->bounded(1500) + 700;
        newLoc =  y() + boundingRect().height() - 65 - QRandomGenerator::global()->bounded(50) ;
        KarenBullet* bullet = new KarenBullet();
        bullet->setPos(x(), newLoc);
        scene()->addItem(bullet);
        bulletTimer.restart();
    }

    if (spawnTimer.elapsed() >=8000){
        EmployeeEnemy * pawn = new EmployeeEnemy(600, 0, x(), 300);
        pawn->setPos(x(), boundingRect().height() + y() - pawn->boundingRect().height());
        scene()->addItem(pawn);
        spawnTimer.restart();
    }
}
