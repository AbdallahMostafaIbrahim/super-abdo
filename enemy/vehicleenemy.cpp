#include "vehicleenemy.h"
#include "level_props/streetbarrier.h"
#include "movingenemy.h"
#include "utils.h"
#include <QPainter>
#include <QGraphicsScene>
#include <QRectF>

VehicleEnemy::VehicleEnemy(int left, int right, int initialPos, int speed) : MovingEnemy(left,right,initialPos,speed,6, 1, true) {
    int width = 275;

    frames << QPixmap(":/images/level-2/street-car/street-car1.png").scaledToWidth(width) << QPixmap(":/images/level-2/street-car/street-car2.png").scaledToWidth(width) << QPixmap(":/images/level-2/street-car/street-car3.png").scaledToWidth(width) << QPixmap(":/images/level-2/street-car/street-car4.png").scaledToWidth(width);

    currentPixmap = &frames[0];
    currentFrame = 0;

    for(auto& frame : frames)
        framesPath.append(*Utils::createPathFromPixmap(frame));

    currentPath = framesPath[0];
}

void VehicleEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap directedPixmap = direction == 1 ? *currentPixmap : currentPixmap->transformed(QTransform().scale(direction, 1));
    painter->drawPixmap(0, 0, directedPixmap);
    if (showDamage) {
        QPainterPath path = currentPath;
        if(direction == -1) {
            QTransform transform = QTransform().scale(direction, 1).translate(-currentPixmap->width(), 0);
            path = transform.map(path);
        }
        painter->setClipPath(path);
        painter->fillRect(boundingRect(), QColor(255, 0, 0, 69)); // red overlay
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF VehicleEnemy::boundingRect() const
{
    return QRectF(0, 0, currentPixmap->width(), currentPixmap->height());
}

const QPixmap* VehicleEnemy::getPixmap()
{
    return currentPixmap;
}

void VehicleEnemy::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = &(frames[currentFrame % frames.size()]);
        currentFrame++;
        animationTimer.restart();
    }
}
