#include "abdo.h"
#include "utils.h"
#include <QBrush>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>

Abdo::Abdo() {
    currentState = IDLE;
    setFlag(ItemClipsToShape);
    idlePixmaps << QPixmap(":/images/abdo/idle1.png").scaled(50,115) << QPixmap(":/images/abdo/idle2.png").scaled(50,115);
    runPixmaps << QPixmap(":/images/abdo/idle1.png").scaled(50,115) << QPixmap(":/abdo/idle2.png").scaled(50,115);
    fallPixmap = QPixmap(":/images/abdo/idle1.png").scaled(50,115);
    jumpPixmap = QPixmap(":/images/abdo/idle1.png").scaled(50,115);

    idlePaths << *Utils::createPathFromPixmap(idlePixmaps[0]) << *Utils::createPathFromPixmap(idlePixmaps[1]);
    runPaths << *Utils::createPathFromPixmap(runPixmaps[0]);
    fallPath = *Utils::createPathFromPixmap(fallPixmap);
    jumpPath = *Utils::createPathFromPixmap(jumpPixmap);

    currentUrl = ":/images/abdo/idle1.png";
    direction = 1;

    currentFrame = 0;

    animate();

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(320);

    showDamage = false;
    damageTimer.setInterval(1000); // 1 second between each hit
    damageTimer.setSingleShot(true);
    connect(&damageTimer, SIGNAL(timeout()), this, SLOT(removeDamageEffect()));
}

QRectF Abdo::boundingRect() const{
    return QRectF(0,0, 50, 115);
}

void Abdo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap directedPixmap = direction == 1 ? currentPixmap : currentPixmap.transformed(QTransform().scale(direction,1));
    painter->drawPixmap(0, 0, currentPixmap.width(), currentPixmap.height(), directedPixmap);

    if (showDamage) {
        if(direction == -1) {
            QTransform transform = QTransform().scale(direction, 1).translate(-currentPixmap.width(), 0);
            painter->setClipPath(transform.map(currentPath));
        } else {
            painter->setClipPath(currentPath);
        }

        painter->fillRect(boundingRect(), QColor(255, 0, 0, 25)); // red overlay
    }

    Q_UNUSED(widget);
    Q_UNUSED(option);
}

void Abdo::setDirection(int dir) {
    direction = dir;
}

int Abdo::getDirection(){
    return direction;
}

GroundEntity* Abdo::isGrounded(const QList<QGraphicsItem*>& items) {
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y() + boundingRect().height() - 5, boundingRect().width(), 5);
            QRectF otherRect(item->x() + item->boundingRect().x(), item->y() + item->boundingRect().y(), item->boundingRect().width(), 5);
            if (rect.intersects(otherRect)) {
                return entity;
            }
        }
    }
    return nullptr;
}


GroundEntity* Abdo::isBlockedHorizontally(const QList<QGraphicsItem*>& items, int& direction) {
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y(), boundingRect().width(), boundingRect().height());
            QRectF leftRect(item->x(), item->y(), 10, item->boundingRect().height());
            if (rect.intersects(leftRect)) {
                direction = 1;
                return entity;
            }
            QRectF rightRect(item->x() + item->boundingRect().width(), item->y(), 10, item->boundingRect().height());
            if (rect.intersects(rightRect)) {
                direction = -1;
                return entity;
            }
        }
    }
    return nullptr;
}


GroundEntity* Abdo::isTouchingHead(const QList<QGraphicsItem*>& items){
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y(), boundingRect().width(), 5);
            QRectF otherRect(item->x(), item->y(), item->boundingRect().width(), item->boundingRect().height());
            if (rect.intersects(otherRect)) {
                return entity;
            }
        }
    }
    return nullptr;
}

Coin* Abdo::isTouchingCoin(const QList<QGraphicsItem*>& items){
    for(QGraphicsItem* item : items) {
        Coin* coin = dynamic_cast<Coin*>(item);
        if(coin != nullptr) {
            return coin;
        }
    }
    return nullptr;
}

HarmfulEntity* Abdo::isTouchingHarmfulEntity(const QList<QGraphicsItem *>& items)
{
    for(QGraphicsItem* item : items) {
        HarmfulEntity* entity = dynamic_cast<HarmfulEntity*>(item);
        if(entity != nullptr) {
            return entity;
        }
    }
    return nullptr;
}


void Abdo::setState(PlayerState state) {
    bool willAnimate = currentState != state;
    currentState = state;
    if(willAnimate) animate();
}

bool Abdo::takeDamage()
{
    if(showDamage == true)
        return false;

    showDamage = true;
    update();
    damageTimer.start();

    return true;
}

void Abdo::animate() {
    switch (currentState) {
        case IDLE:
            currentPixmap = (idlePixmaps[currentFrame % idlePixmaps.size()]);
            currentPath = (idlePaths[currentFrame % idlePaths.size()]);
            break;
        case RUNNING:
            currentPixmap = (runPixmaps[currentFrame % runPixmaps.size()]);
            currentPath = (runPaths[currentFrame % runPaths.size()]);
            break;
        case JUMPING:
            currentPixmap = (jumpPixmap);
            currentPath = (jumpPath);
            break;
        case FALLING:
            currentPixmap = (fallPixmap);
            currentPath = (fallPath);
            break;
    }

    currentFrame++;
    update();
}

void Abdo::removeDamageEffect()
{
    showDamage = false;
    update();
}

