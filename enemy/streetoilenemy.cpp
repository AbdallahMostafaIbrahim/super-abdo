#include "streetoilenemy.h"
#include "utils.h"
#include <QPainter>
#include <QRectF>

StreetOilEnemy::StreetOilEnemy(int left, int right, int initialPos, int speed) : MovingEnemy(left, right, initialPos, speed, 3, 1) {
    idle = QPixmap(":/images/level-2/street-oilenemy/street-oilenemy1.gif").scaledToWidth(100);
    walking = QPixmap(":/images/level-2/street-oilenemy/street-oilenemy2.gif").scaledToWidth(100);
    pixmap = &idle;
    isIdle = true;

    idlePath = *Utils::createPathFromPixmap(idle);
    walkingPath = *Utils::createPathFromPixmap(walking);
}
void StreetOilEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QRectF StreetOilEnemy::boundingRect() const
{
    return QRectF(0, 0, pixmap->width(), pixmap->height());
}

const QPixmap* StreetOilEnemy::getPixmap()
{
    return pixmap;
}

void StreetOilEnemy::animate()
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
