#include "janitor.h"
#include "utils.h"
#include <QPainter>
#include <QRectF>



Janitor::Janitor(int left, int right, int initialPos, int speed) : MovingEnemy(left, right, initialPos, speed, 3, 1) {
    idle = QPixmap(":/images/level-4/janitor.png").scaledToWidth(180);
    walking = QPixmap(":/images/level-4/janitor.png").scaledToWidth(180);
    pixmap = &idle;
    isIdle = true;

    idlePath = *Utils::createPathFromPixmap(idle);
    walkingPath = *Utils::createPathFromPixmap(walking);
}

void Janitor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QRectF Janitor::boundingRect() const
{
    return QRectF(20, 20, pixmap->width()-40, pixmap->height()-40);
}

const QPixmap* Janitor::getPixmap()
{
    return pixmap;
}

void Janitor::animate()
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
