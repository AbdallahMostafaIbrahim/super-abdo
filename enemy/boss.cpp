#include "boss.h"
#include "utils.h"
#include "level1.h"
#include <QRandomGenerator>
#include <QPainter>
#include <QPainterPath>
#include <QTransform>

Boss::Boss(QList<QPixmap> pixie, int h) : BaseEnemy(h, 1, false)
{
    int width = 250;
    pixmaps = pixie;
    for(int i = 0; i < pixmaps.length(); i++) {
        paths.append(*Utils::createPathFromPixmap(pixmaps[i]));
    }
    currentPixmap = pixmaps[0];
    currentPath = paths[0];
    currentFrame = 0;
    dropRate = QRandomGenerator::global()->bounded(10) + 7;
}

void Boss::move(int, int)
{

}

void Boss::shoot(int)
{
    // if(currentFrame % dropRate == 0) {
    //     PrinterBullet* bullet = new PrinterBullet();
    //     bullet->setPos(x() + bullet->boundingRect().width() / 4, y() + currentPixmap.height());
    //     scene()->addItem(bullet);
    // }
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, currentPixmap);
    if (showDamage) {
        painter->setClipPath(currentPath);
        painter->fillRect(boundingRect(), QColor(255, 0, 0, 69)); // red overlay
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Boss::boundingRect() const
{
    return QRectF(0, 0, currentPixmap.width(), currentPixmap.height());
}

void Boss::animate()
{
    currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
    currentPath = (paths[currentFrame % paths.size()]);
    currentFrame++;
}

void Boss::kill()
{
    Level1* level = dynamic_cast<Level1*>(scene());
    if(level) {
        level->killBoss();
    }
    BaseEnemy::kill();
}
