#include "baselevel.h"
#include "abdo.h"
#include "levelloader.h"
#include "utils.h"
#include "soundwave.h"
#include "enemy/baseenemy.h"
#include "enemy/enemybullet.h"
#include "enemy/boss.h"
#include "enemy/karen.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QUrl>
#include <QMessageBox>
#include <QKeyEvent>
#include <QScrollBar>
#include "soundplayer.h"
#include <QPushButton>

#define TERMINAL_VELOCITY 4.0
#define MAX_HEALTH 3

BaseLevel::BaseLevel(Game *game) : QGraphicsScene()
{
    this->game = game;

    QTimer *timer = new QTimer(this);

    // KeyPresses default to false
    rightPressed = false;
    leftPressed = false;
    spacePressed = false;
    shootPressed = false;

    // Movement
    elapsedTime = 0;
    speed = 750; // I think this means 750 pixels in 1 second
    timeAfterJump = 0;
    timeWhenStartedFalling = 0;
    speedJumpFactor = 0.8f;
    jumpWidth = 32;
    jumpHeight = 180;
    isJumping = false;
    isFalling = true;

    // Stats
    health = MAX_HEALTH;
    collectedCoins = 0;
    currentJumpCount = 0;
    maxJumps = 2;
    isGameOver = false;
    isGoodGame = false;
    finishedTime = 0;

    // Boss Init
    isFightingBoss = false;

    // Connect and start the game loop
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(0);
    elapsedTimer.start();

    // gameTheme
    SoundPlayer::gameTheme();
}

BaseLevel::~BaseLevel()
{
    SoundPlayer::gameTheme(false);
    delete abdo;
    disconnect();
    clear();
}

void BaseLevel::initScene() {
    setSceneRect(0, 0, getLevelSettings().sceneWidth, game->height());
    setBackgroundBrush(QBrush(QPixmap(":/images/background-1.png").scaledToHeight(game->height())));

    abdo = new Abdo();

    abdo->setPos(200, game->height() - abdo->boundingRect().height() - 100);

    addItem(abdo);

    QFile mapFile(getLevelSettings().mapFile);
    QFile enemiesFile(getLevelSettings().enemiesFile);
    LevelLoader loader(mapFile, enemiesFile);
    loader.fillScene(this);
}

void BaseLevel::killBoss()
{
    isFightingBoss = false;
    isGoodGame = true;
    finishedTime = elapsedTime;
}


void BaseLevel::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->resetTransform();
    if(isGoodGame) {
        painter->drawRect(sceneRect());
        painter->fillRect(sceneRect(), QColor(0, 0, 0, 120));
        painter->setPen(Qt::white);
        painter->setFont(QFont("Minecraft", 48));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 - 50, "GOOD GAME BRO");

        painter->setFont(QFont("Minecraft", 24));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2, "Coins Collected: " + QString::number(collectedCoins));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 35, "Time spent: " + QString::number(finishedTime / (1000)) + " seconds");

        painter->setFont(QFont("Minecraft", 18));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 75, "Press Enter to continue.");
    }
    else if (!isGameOver) {
        for (int i = 0; i < health; i++)
        {
            painter->drawPixmap(i * 45 + 10, 25, 40, 40, QPixmap(":/images/heart.png").scaled(40, 40));
        }

        painter->drawPixmap(10, 75, 40, 40, QPixmap(":/images/coin.png").scaled(40, 40));

        painter->setPen(Qt::white);
        painter->setFont(QFont("Minecraft", 24));
        painter->drawText(55, 75 + 30, "x" + QString::number(collectedCoins));

        painter->drawText(game->width() - 300, 80, QString::number(1000.0f/deltaTime) + "Updates Per Second");

        if(isFightingBoss) {
            int healthBarWidth = 400;
            if(!boss) return;
            QRectF outerHealthBar(game->width() / 2 - healthBarWidth / 2, 50, healthBarWidth, 20);
            painter->drawRoundedRect(outerHealthBar, 5, 5);
            int width = ((double)boss->getHealth() / (double)boss->getInitialHealth()) * healthBarWidth;
            QRectF innerHealth(game->width() / 2 - healthBarWidth / 2, 50, width, 20);
            painter->drawRoundedRect(innerHealth, 5, 5);
            painter->fillRect(innerHealth, QBrush(Qt::red));
        }
    } else {
        painter->drawRect(sceneRect());
        painter->fillRect(sceneRect(), QColor(0, 0, 0, 120));
        painter->setPen(Qt::white);
        painter->setFont(QFont("Minecraft", 48));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 - 50, "GAME OVER");

        painter->setFont(QFont("Minecraft", 24));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2, "Coins Collected: " + QString::number(collectedCoins));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 35, "Time spent: " + QString::number(finishedTime / (1000)) + " seconds");

        painter->setFont(QFont("Minecraft", 18));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 75, "Press R to restart.");
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 100, "Press ESC to go to main menu.");
    }
}

float BaseLevel::jumpFunction(int time)
{
    return -pow((time / jumpWidth) - sqrt(jumpHeight), 2) + jumpHeight;
}

float BaseLevel::fallFunction(int time)
{
    if (getLevelSettings().galabeyaGlideEnabled)
    {
        if (spacePressed)
        {
            return -pow(time / (jumpWidth * 3), 2);
        }
        else
        {
            return -pow(time / (jumpWidth), 2);
        }
    }
    else
    {
        return -pow(time / jumpWidth, 2);
    }
}

void BaseLevel::moveHorizontally()
{
    if (leftPressed && rightPressed)
        return;
    if (!leftPressed && !rightPressed)
        return;
    if (abdo->x() <= 0 && leftPressed)
        return;
    if (abdo->x() >= sceneRect().width()-abdo->boundingRect().width() && rightPressed)
        return;

    int direction = 0;
    GroundEntity *blocked = abdo->isBlockedHorizontally(collidingItems, direction);

    if (direction == 1 && rightPressed && blocked)
    {
        return;
    }
    if (direction == -1 && leftPressed && blocked)
    {
        return;
    }

    abdo->moveBy(speed * (leftPressed ? -1 : 1) * ((isJumping | isFalling) ? speedJumpFactor : 1) * (deltaTime / 1000.0f), 0);
}

void BaseLevel::jumpPlayer()
{
    isJumping = true;
    abdo->moveBy(0, -1);
    timeAfterJump = deltaTime;
    abdo->setState(JUMPING);
}

void BaseLevel::fallPlayer()
{
    isJumping = false;
    timeAfterJump = 0;
    isFalling = true;
    abdo->setState(FALLING);
}

void BaseLevel::moveVertically()
{
    GroundEntity *ground = abdo->isGrounded(collidingItems);
    if (ground)
    {
        isFalling = false;
        if (spacePressed && !isJumping)
            jumpPlayer();
        else
        {
            abdo->setPos(abdo->x(), ground->y() + ground->boundingRect().y() - abdo->boundingRect().height());
            isJumping = false;
            timeAfterJump = 0;
            currentJumpCount = 0;
            abdo->setState(IDLE);
        }
    }
    else
    {
        if (isJumping)
        {
            float deltaY = Utils::minMagnitude(jumpFunction(timeAfterJump) - (jumpFunction(timeAfterJump - deltaTime)), TERMINAL_VELOCITY);
            abdo->moveBy(0, -deltaY);
            timeAfterJump += deltaTime;

            // Character is falling now
            if (deltaY < 0)
                fallPlayer();

            // Check if something is touching my head
            GroundEntity *ceiling = abdo->isTouchingHead(collidingItems);
            if (ceiling)
                fallPlayer();
        }
        else
        {
            float deltaY = Utils::minMagnitude((fallFunction(timeAfterJump) - (timeAfterJump == 0 ? 0 : fallFunction(timeAfterJump - deltaTime))), TERMINAL_VELOCITY);
            abdo->moveBy(0, -deltaY);
            timeAfterJump += deltaTime;
        }
        if(abdo->y() > game->height() + 50) {
            removeItem(abdo);
            isGameOver = true;
            finishedTime = elapsedTime;
        }
    }
}

void BaseLevel::checkCoins()
{
    Coin *coin = abdo->isTouchingCoin(collidingItems);

    if (coin)
    {
        removeItem(coin);
        collectedCoins++;
    }
}

void BaseLevel::checkEnemies() {
    HarmfulEntity *harmfulEntity = abdo->isTouchingHarmfulEntity(collidingItems);

    if (harmfulEntity)
    {
        bool ok = abdo->takeDamage();
        if(ok){
            SoundPlayer::hitAbdo();
            health -= harmfulEntity->getDamage();
            if(health <= 0) {
                removeItem(abdo);
                isGameOver = true;
                finishedTime = elapsedTime;
                // TODO: Game Over Sound
            }
        }
    }
}

void BaseLevel::moveEnemies()
{
    QList<QGraphicsItem*> things = items();
    for(int i = 0; i < things.length(); i++) {
        if(!things[i]) continue;
        BaseEnemy* enemy = dynamic_cast<BaseEnemy*>(things[i]);
        if(enemy) {
            enemy->move(elapsedTime, deltaTime);
            enemy->animate();
        }

    }
}

void BaseLevel::moveBullets()
{
    QList<QGraphicsItem*> things = items();
    for(int i = 0; i < things.length(); i++) {
        if(!things[i]) continue;
        EnemyBullet* bullet = dynamic_cast<EnemyBullet*>(things[i]);
        if(bullet)
        {
            bullet->move();
        }
    }
}

void BaseLevel::spawnBoss() {
    if(abdo->x() >= getLevelSettings().triggerBossLoc && !isFightingBoss)
    {
        boss = new Karen;
        boss->setPos(sceneRect().width() - boss->boundingRect().width()-50, sceneRect().height()-55 - boss->boundingRect().height());
        isFightingBoss = true;
        addItem(boss);
    }
}

void BaseLevel::gameLoop()
{
    deltaTime = elapsedTimer.restart();
    elapsedTime += deltaTime;

    if(!isGameOver && !isGoodGame) {
        collidingItems = abdo->collidingItems();
        moveHorizontally();
        moveVertically();
        checkCoins();
        checkEnemies();
        spawnBoss();
        game->ensureVisible(abdo, 500, 0);
    }

    moveBullets();
    moveEnemies();

    update();
}


void BaseLevel::keyPressEvent(QKeyEvent *event)
{
    if(!isGameOver && !isGoodGame) {
        switch (event->key())
        {
        case Qt::Key_Space:
            if (getLevelSettings().doubleJumpEnabled && (isJumping || isFalling) && !spacePressed)
            {
                if (currentJumpCount < maxJumps - 1)
                {
                    jumpPlayer();
                    currentJumpCount++;
                    SoundPlayer::doubleJump();
                }
            }
            if (currentJumpCount == 0)
                SoundPlayer::abdoJump();
            spacePressed = true;
            break;
        case Qt::Key_Right:
            rightPressed = true;
            abdo->setDirection(1);
            break;
        case Qt::Key_Left:
            leftPressed = true;
            abdo->setDirection(-1);
            break;
        case Qt::Key_Z:
            if (getLevelSettings().soundWaveEnabled && !shootPressed)
            {
                SoundPlayer::fireSoundWave();
                SoundWave *s = new SoundWave(abdo->getDirection());
                s->setPos(abdo->x() + 20 * abdo->getDirection(), abdo->y() + abdo->boundingRect().height() / 4);
                this->addItem(s);
                shootPressed = true;
            }
        }
    }
    else if(isGameOver) {
        switch (event->key())
        {
        case Qt::Key_R:
        {
            emit restart();
        }
        break;
        case Qt::Key_Escape:
        {
            emit quit();
        }
        break;
        }
    }
}

void BaseLevel::keyReleaseEvent(QKeyEvent *event)
{
    if(!isGameOver && !isGoodGame)
        switch (event->key())
        {
        case Qt::Key_Right:
            rightPressed = false;
            break;
        case Qt::Key_Left:
            leftPressed = false;
            break;
        case Qt::Key_Space:
            spacePressed = false;
            break;
        case Qt::Key_Z:
            shootPressed = false;
            break;
        }

}
