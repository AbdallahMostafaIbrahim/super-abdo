#include "boss.h"
#include "utils.h"
#include "baselevel.h"
#include <QRandomGenerator>
#include <QPainter>
#include <QPainterPath>
#include <QTransform>

Boss::Boss(QList<QPixmap> pixie, int h) : BaseEnemy(h, 1, false)
{
    // Setup pixmaps
    pixmaps = pixie;
    for(int i = 0; i < pixmaps.length(); i++) {
        paths.append(*Utils::createPathFromPixmap(pixmaps[i], 5));
    }
    currentPixmap = pixmaps[0];
    currentPath = paths[0];
    currentFrame = 0;
}

// Boss Doesn't Move
void Boss::move(int, int) { }

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
    // if (showDamage) {
    //      painter->setClipPath(currentPath);
    //      painter->fillRect(boundingRect(), QColor(255, 0, 0, 69)); // red overlay
    //  }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Boss::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void Boss::animate()
{
    shoot();
    if(animationTimer.elapsed() >= 100) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentPath = (paths[currentFrame % paths.size()]);
        currentFrame++;
        animationTimer.restart();
    }
}

void Boss::kill()
{
    BaseLevel* level = dynamic_cast<BaseLevel*>(scene());
    if(level) {
        level->killBoss();
    }
    BaseEnemy::kill();
}
