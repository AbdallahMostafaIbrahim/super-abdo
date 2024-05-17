#include "leonardo.h"
#include "utils.h"
#include <QPainter>
#include <QRectF>

Leonardo::Leonardo(int left, int right, int initialPos, int speed) : MovingEnemy(left, right, initialPos, speed, 3, 1) {

    frames << QPixmap(":/images/level-3/leonardo/frame_0_delay-0.1s.png").scaledToWidth(100) << QPixmap(":/images/level-3/leonardo/frame_1_delay-0.1s.png").scaledToWidth(100) << QPixmap(":/images/level-3/leonardo/frame_2_delay-0.1s.png").scaledToWidth(100) << QPixmap(":/images/level-3/leonardo/frame_3_delay-0.1s.png").scaledToWidth(100);

    currentPixmap = &frames[0];
    currentFrame = 0;

    for(auto& frame : frames )
        framesPath.append(*Utils::createPathFromPixmap(frame));

    currentPath = framesPath[0];
}

void Leonardo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QRectF Leonardo::boundingRect() const
{
    return QRectF(0, 0, currentPixmap->width() - 35, currentPixmap->height() - 35);
}

const QPixmap* Leonardo::getPixmap()
{
    return currentPixmap;
}

void Leonardo::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = &(frames[currentFrame % frames.size()]);
        currentFrame++;
        animationTimer.restart();
    }
}
