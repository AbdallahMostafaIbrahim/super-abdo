#include "splinter.h"
#include "splinterbullet.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "leonardo.h"

Splinter::Splinter() : Boss({QPixmap(":/images/Level 3/Splinter/frame_00_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_01_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_02_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_03_delay-0.12s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_04_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_05_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_06_delay-0.16s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_07_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_08_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_09_delay-0.12s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_10_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_11_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_12_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_13_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_14_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_15_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_16_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_17_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_18_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_19_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_20_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_21_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_22_delay-0.04s.png").scaledToWidth(300),
               QPixmap(":/images/Level 3/Splinter/frame_23_delay-0.04s.png").scaledToWidth(300)}, 25)
{
    bulletTimer.start();
    spawnTimer.start();
    recoilRate = QRandomGenerator::global()->bounded(1500) + 700;
    newLoc = QRandomGenerator::global()->bounded(12) + 9;
}

void Splinter::shoot()
{
    if(bulletTimer.elapsed() > recoilRate)    {
        recoilRate = QRandomGenerator::global()->bounded(1500) + 700;
        newLoc =  y() + boundingRect().height() - 65 - QRandomGenerator::global()->bounded(50) ;
        SplinterBullet* bullet = new SplinterBullet();
        bullet->setPos(x(), newLoc);
        scene()->addItem(bullet);
        bulletTimer.restart();
    }

    if (spawnTimer.elapsed() >=8000){
        Leonardo * pawn = new Leonardo(600, 0, x(), 300);
        pawn->setPos(x(), boundingRect().height() + y() - 30 - pawn->boundingRect().height());
        scene()->addItem(pawn);
        spawnTimer.restart();
    }
}
