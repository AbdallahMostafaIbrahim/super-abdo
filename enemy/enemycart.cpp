#include "enemycart.h"
#include "soundplayer.h"
#include "utils.h"
#include <QPainter>
#include <QRectF>

EnemyCart::EnemyCart(int left, int right, int initialPos, int speed) : MovingEnemy(left, right, initialPos, speed, 3, 1) {
    idle = QPixmap(":/images/level-4/baby_cart2.png").scaledToWidth(160);
    walking = QPixmap(":/images/level-4/baby_cart2.png").scaledToWidth(160);
    pixmap = &idle;
    isIdle = true;

    idlePath = *Utils::createPathFromPixmap(idle);
    walkingPath = *Utils::createPathFromPixmap(walking);
}

void EnemyCart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

QRectF EnemyCart::boundingRect() const
{
    return QRectF(0, 0, pixmap->width(), pixmap->height());
}

const QPixmap* EnemyCart::getPixmap()
{
    return pixmap;
}

EnemyCart::~EnemyCart()
{
    SoundPlayer::babyCrying();
}

void EnemyCart::animate()
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

