#include "level1.h"
#include "abdo.h"
#include "levelloader.h"
#include "utils.h"
#include "soundwave.h"
#include "enemy/baseenemy.h"
#include "mainmenuscene.h"
#include "basebullet.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
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

Level1::Level1(Game *game) : QGraphicsScene()
{
    this->game = game;

    QTimer *timer = new QTimer(this);

    // KeyPresses default to false
    rightPressed = false;
    leftPressed = false;
    spacePressed = false;
    shootPressed = false;
    galabeyaGlideEnabled = false;
    doubleJumpEnabled = false;
    soundWaveEnabled = true;
    deltaTime = 5;

    // Movement
    elapsedTime = 0;
    speed = 3;
    timeAfterJump = 0;
    timeWhenStartedFalling = 0;
    speedJumpFactor = 0.8f;
    jumpWidth = 30;
    jumpHeight = 160;
    isJumping = false;
    isFalling = true;

    // Stats
    health = MAX_HEALTH;
    collectedCoins = 0;
    currentJumpCount = 0;
    maxJumps = 2;
    isGameOver = false;
    finishedTime = 0;

    // Connect and start the game loop
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(deltaTime);

    // Scene Init
    initScene();

    // gameTheme
    SoundPlayer::gameTheme();
}

void Level1::initScene()
{
    // Set the scene width to be a big number
    this->setSceneRect(0, 0, 8100, game->height());
    this->setBackgroundBrush(QBrush(QPixmap(":/images/background-1.png").scaledToHeight(game->height())));

    // Create the player (abdo)
    abdo = new Abdo();

    abdo->setPos(50, 0);

    this->addItem(abdo);

    // Open Map File to load the platforms
    QFile file(":/maps/map-1/map.txt");
    QFile enemiesFile(":/maps/map-1/enemies.txt");
    LevelLoader loader(file, enemiesFile);
    loader.fillScene(this);
}

void Level1::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->resetTransform();
    if(!isGameOver) {
        for (int i = 0; i < health; i++)
        {
            painter->drawPixmap(i * 45 + 10, 25, 40, 40, QPixmap(":/images/heart.png").scaled(40, 40));
        }

        painter->drawPixmap(10, 75, 40, 40, QPixmap(":/images/coin.png").scaled(40, 40));

        painter->setPen(Qt::white);
        painter->setFont(QFont("Minecraft", 24));
        painter->drawText(55, 75 + 30, "x" + QString::number(collectedCoins));
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

float Level1::jumpFunction(int time)
{
    return -pow((time / jumpWidth) - sqrt(jumpHeight), 2) + jumpHeight;
}

float Level1::fallFunction(int time)
{
    if (galabeyaGlideEnabled)
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

void Level1::moveHorizontally()
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

    abdo->moveBy(speed * (leftPressed ? -1 : 1) * ((isJumping | isFalling) ? speedJumpFactor : 1), 0);
}

void Level1::jumpPlayer()
{
    isJumping = true;
    abdo->moveBy(0, -1);
    timeAfterJump = deltaTime;
    abdo->setState(JUMPING);
}

void Level1::fallPlayer()
{
    isJumping = false;
    timeAfterJump = 0;
    isFalling = true;
    abdo->setState(FALLING);
}

void Level1::moveVertically()
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
    }
}

void Level1::checkCoins()
{
    Coin *coin = abdo->isTouchingCoin(collidingItems);

    if (coin)
    {
        removeItem(coin);
        collectedCoins++;
    }
}

void Level1::checkEnemies() {
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

void Level1::moveEnemies()
{
    QList<QGraphicsItem*> things = items();
    for(int i = 0; i < things.length(); i++) {
        if(!things[i]) continue;
        BaseEnemy* enemy = dynamic_cast<BaseEnemy*>(things[i]);
        if(enemy)
            enemy->move(elapsedTime, deltaTime);
    }
}

void Level1::moveBullets()
{
    QList<QGraphicsItem*> things = items();
    for(int i = 0; i < things.length(); i++) {
        if(!things[i]) continue;
        BaseBullet* bullet = dynamic_cast<BaseBullet*>(things[i]);
        if(bullet)
        {
            bullet->move();
        }
    }
}

void Level1::gameLoop()
{
    elapsedTime += deltaTime;

    if(!isGameOver) {
        collidingItems = abdo->collidingItems();
        moveHorizontally();
        moveVertically();
        checkCoins();
        checkEnemies();
        game->ensureVisible(abdo, 500, 0);
    }

    moveBullets();
    moveEnemies();

    update();
}

void Level1::keyPressEvent(QKeyEvent *event)
{
    if(!isGameOver) {
        switch (event->key())
        {
        case Qt::Key_Space:
            if (doubleJumpEnabled && (isJumping || isFalling) && !spacePressed)
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
            if (soundWaveEnabled && !shootPressed)
            {
                SoundPlayer::fireSoundWave();
                SoundWave *s = new SoundWave(abdo->getDirection());
                s->setPos(abdo->x() + 20 * abdo->getDirection(), abdo->y() + abdo->boundingRect().height() / 4);
                this->addItem(s);
                shootPressed = true;
            }
        }
    }
    else {
        switch (event->key())
        {
        case Qt::Key_R:
        {
            Level1* level1 = new Level1(game);
            game->setScene(level1);
            delete this;
        }
            break;
        case Qt::Key_Escape:
        {
            MainMenuScene* mainMenuScene = new MainMenuScene(game);
            game->setScene(mainMenuScene);
            delete this;
        }
            break;
        }
    }
}

void Level1::keyReleaseEvent(QKeyEvent *event)
{
    if(!isGameOver)
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
