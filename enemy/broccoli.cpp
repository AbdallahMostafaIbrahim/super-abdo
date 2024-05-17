#include "broccoli.h"
#include "karenbullet.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "janitor.h"

int width = 300;
Broccoli::Broccoli() : Boss({
             QPixmap(":/images/level-4/broccoli/frame_00_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_01_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_02_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_03_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_04_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_05_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_06_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_07_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_08_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_09_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_10_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_11_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_12_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_13_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_14_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_15_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_16_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_17_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_18_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_19_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_20_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_21_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_22_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_23_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_24_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_25_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_26_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_27_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_28_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_29_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_30_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_31_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_32_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_33_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_34_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_35_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_36_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_37_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_38_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_39_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_40_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_41_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_42_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_43_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_44_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_45_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_46_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_47_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_48_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_49_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_50_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_51_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_52_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_53_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_54_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_55_delay-0.1s.png").scaledToWidth(width),
             QPixmap(":/images/level-4/broccoli/frame_56_delay-0.1s.png").scaledToWidth(width)
           }, 20) {

        bulletTimer.start();
        spawnTimer.start();
        recoilRate = QRandomGenerator::global()->bounded(1500) + 700;
        newLoc = QRandomGenerator::global()->bounded(12) + 9;

}

void Broccoli::shoot()
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
        Janitor * pawn = new Janitor(600, 0, x(), 300);
        pawn->setPos(x(), boundingRect().height() + y() - pawn->boundingRect().height());
        scene()->addItem(pawn);
        spawnTimer.restart();
    }
}
