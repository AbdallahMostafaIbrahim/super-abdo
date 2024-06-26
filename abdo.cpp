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
    // Draws the player's pixmap
    QPixmap directedPixmap = direction == 1 ? currentPixmap : currentPixmap.transformed(QTransform().scale(direction,1));
    painter->drawPixmap(0, 0, currentPixmap.width(), currentPixmap.height(), directedPixmap);

    // If he is being damaged, draw the red overlay using the setClipPath method.
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

// Checks if player is touching a groundentity from his feet
GroundEntity* Abdo::isGrounded(const QList<QGraphicsItem*>& items) {
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y() + boundingRect().height() - 5, boundingRect().width(), 5);
            QRectF otherRect(item->x() + item->boundingRect().x() + 6, item->y() + item->boundingRect().y(), item->boundingRect().width() - 3, 5);
            if (rect.intersects(otherRect)) {
                return entity;
            }
        }
    }
    return nullptr;
}

// Checks if player is touching a groundentity from the sides.
GroundEntity* Abdo::isBlockedHorizontally(const QList<QGraphicsItem*>& items, int& direction) {
    direction = 0;
    for(QGraphicsItem* item : items) {
        GroundEntity* entity = dynamic_cast<GroundEntity*>(item);
        if(entity != nullptr) {
            QRectF rect(x(), y(), boundingRect().width(), boundingRect().height());
            QRectF leftRect(item->x() - 3, item->y() + 3, 10, item->boundingRect().height() - 6);
            if (rect.intersects(leftRect)) {
                direction += 1;
                return entity;
            }
            QRectF rightRect(item->x() + item->boundingRect().width() + 3, item->y() + 3, 10, item->boundingRect().height() - 6);
            if (rect.intersects(rightRect)) {
                direction -= 1;
                return entity;
            }
        }
    }
    return nullptr;
}

// Checks if player is touching a groundenitity from his head.
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

// Checks if player collided with coin
Coin* Abdo::isTouchingCoin(const QList<QGraphicsItem*>& items){
    for(QGraphicsItem* item : items) {
        Coin* coin = dynamic_cast<Coin*>(item);
        if(coin != nullptr) {
            return coin;
        }
    }
    return nullptr;
}

Oil *Abdo::isTouchingOil(const QList<QGraphicsItem *> & items)
{
    for(QGraphicsItem* items : items) {
        Oil* oil = dynamic_cast<Oil*>(items);
        if(oil != nullptr) {
            return oil;
        }
    }
    return nullptr;
}

// Checks if player collided with any harmful entity
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

// Changes Animation State of Player (still work in progress)
void Abdo::setState(PlayerState state) {
    bool willAnimate = currentState != state;
    currentState = state;
    if(willAnimate) animate();
}

// Gets Called when touches harmful entity to show red overlay over player (it is throttled)
bool Abdo::takeDamage()
{
    if(showDamage == true)
        return false;

    showDamage = true;
    update();
    damageTimer.start();

    return true;
}

// Cycle Through pixmaps depending on state
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

