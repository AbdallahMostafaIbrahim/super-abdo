#include "leonardo.h"
#include "utils.h"
#include <QPainter>
#include <QRectF>

Leonardo::Leonardo(int left, int right, int initialPos, int speed) : MovingEnemy(left, right, initialPos, speed, 3, 1) {
    f0 = QPixmap(":/images/Level 3/leonardo/frame_0_delay-0.1s.png").scaledToWidth(50);
    f1 = QPixmap(":/images/Level 3/leonardo/frame_1_delay-0.1s.png").scaledToWidth(50);
    f2 = QPixmap(":/images/Level 3/leonardo/frame_2_delay-0.1s.png").scaledToWidth(50);
    f3 = QPixmap(":/images/Level 3/leonardo/frame_3_delay-0.1s.png").scaledToWidth(50);

    pixmap = &f0;
    isChanged = true;

    f0Path = *Utils::createPathFromPixmap(f0);
    f1Path = *Utils::createPathFromPixmap(f1);
    f2Path = *Utils::createPathFromPixmap(f2);
    f3Path = *Utils::createPathFromPixmap(f3);

}

void Leonardo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap directedPixmap = direction == 1 ? *pixmap : pixmap->transformed(QTransform().scale(direction, 1));
    painter->drawPixmap(0, 0, directedPixmap);
    if (showDamage) {
        QPainterPath path = isIdle ? idlePath : walkingPath;
        if(direction == -1) {
            QTransform transform = QTransform().scale(direction, 1).translate(-pixmap->width(), 0);
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
    return QRectF(0, 0, pixmap->width(), pixmap->height());
}

const QPixmap* Leonardo::getPixmap()
{
    return pixmap;
}

void Leonardo::animate()
{
    if(animationTimer.elapsed() >= 200) {
        if(isIdle)
            pixmap = &walking;
        else
            pixmap = &idle;

        isIdle = !isIdle;
        animationTimer.restart();
    }
}
