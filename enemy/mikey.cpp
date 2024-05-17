#include "mikey.h"
#include "scythe.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRandomGenerator>

Mikey::Mikey() : BaseEnemy(100,1,true) {
    int width = 100;
    pixmaps << QPixmap(":/images/level-3/micheal_angelo/frame_0_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/level-3/micheal_angelo/frame_1_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/level-3/micheal_angelo/frame_2_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/level-3/micheal_angelo/frame_3_delay-0.1s.png").scaledToWidth(width);
    currentPixmap = &pixmaps[0];
    currentFrame = 0;
    // The drop rate is a random number so that not all printers drop papers in sync.
    dropRate = QRandomGenerator::global()->bounded(5) + 25;
}


void Mikey::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *currentPixmap);
}

QRectF Mikey::boundingRect() const
{
    return QRectF(0, 0, pixmaps[0].width(), pixmaps[0].height());
}

void Mikey::move(int, int)
{
}

const QPixmap* Mikey::getPixmap()
{
    return currentPixmap;
}

void Mikey::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = &(pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        // IF currentframe is divisible by the random drop rate, we will spawn the bullet.
        if(currentFrame % dropRate == 0) {
            Scythe* scythe1 = new Scythe();
            Scythe* scythe2 = new Scythe();
            Scythe* scythe3 = new Scythe();

            scythe1->setPos(x(), y() - 100);
            scythe2->setPos(x() + 100, y() - 50);
            scythe3->setPos(x() - 100, y() - 50);
            scene()->addItem(scythe1);
            scene()->addItem(scythe2);
            scene()->addItem(scythe3);

            Scythe* scythe4 = new Scythe();
            Scythe* scythe5 = new Scythe();
            Scythe* scythe6 = new Scythe();

            scythe4->setPos(x(), y() + 100);
            scythe5->setPos(x() + 100, y() + 50);
            scythe6->setPos(x() - 100, y() + 50);
            scene()->addItem(scythe4);
            scene()->addItem(scythe5);
            scene()->addItem(scythe6);
        }
        animationTimer.restart();
    }
}

