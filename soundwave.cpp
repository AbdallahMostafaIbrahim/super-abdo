#include "soundwave.h"
#include "enemy/baseenemy.h"
#include "level_props/groundentity.h"
#include <QTimer>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

SoundWave::SoundWave(int direction)//constructor of soudwave
{
    pixmap = QPixmap(":/images/sound-wave.png");
    dir = direction;

    QTimer::singleShot(2000, this, SLOT(kill()));

    // Bullet timer initialization.
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000 / 60);
}

QRectF SoundWave::boundingRect() const {
    return QRectF(0, 0, 40, 40);
}

void SoundWave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->drawPixmap(0,0, 40, 40, dir == 1 ? pixmap : pixmap.transformed(QTransform().scale(dir,1)));

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void SoundWave::move(){
    // Gets called 60 times per second and moves in the direction the player was facing.
    moveBy(7 * dir, 0);

    QList<QGraphicsItem*> items = collidingItems();

    // If collides with enemy or ground entity it deletes itself
    // If it collides with enemy it damages the enemy.
    for(QGraphicsItem* item : items) {
        if (!item) continue;

        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity) {
            return kill();
        }
        BaseEnemy* enemy = dynamic_cast<BaseEnemy*>(item);
        if(enemy) {
            enemy->damage(1);
            return kill();
        }
    }
}


void SoundWave::kill() {
    scene()->removeItem(this);
    delete this;
}
