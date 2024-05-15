#include "baselevel.h"
#include "abdo.h"
#include "levelloader.h"
#include "utils.h"
#include "soundwave.h"
#include "enemy/baseenemy.h"
#include "enemy/enemybullet.h"
#include "enemy/boss.h"
#include "gamestate.h"
#include "soundplayer.h"
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
#include <QPushButton>

// Some Constants
#define TERMINAL_VELOCITY 4.0
#define MAX_HEALTH 3

BaseLevel::BaseLevel(Game *game) : QGraphicsScene()
{
    this->game = game;

    QTimer *timer = new QTimer(this);

    // Level Settings Init
    doubleJumpEnabled = GameState::itemsBought.contains(DOUBLE_JUMP);
    galabeyaGlideEnabled = GameState::itemsBought.contains(GALABEYA_GLIDE);
    soundWaveEnabled = true;
    firstTimeDoubleJumping = GameState::newlyPurchased.contains(DOUBLE_JUMP);
    firstTimeGliding = GameState::newlyPurchased.contains(GALABEYA_GLIDE);

    // KeyPresses default to false
    rightPressed = false;
    leftPressed = false;
    spacePressed = false;
    shootPressed = false;

    // Movement
    elapsedTime = 0;
    speed = 750;
    initalSpeed = speed;
    timeAfterJump = 0;
    timeWhenStartedFalling = 0;
    timeWhenShot = 0;
    speedJumpFactor = 0.9f;
    jumpWidth = 30;
    jumpHeight = 180;
    isJumping = false;
    isFalling = true;

    // Default Stats in the beginning
    health = MAX_HEALTH;
    collectedCoins = 0;
    currentJumpCount = 0;
    maxJumps = 2;
    isGameOver = false;
    isGoodGame = false;
    isTeleport = false;
    finishedTime = 0;
    isFightingBoss = false;

    // Connect and start the game loop
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    timer->start(5);
    elapsedTimer.start();

    // Play Game Theme Song
    SoundPlayer::gameTheme();
}

// Stop Song and clean up
BaseLevel::~BaseLevel()
{
    SoundPlayer::gameTheme(false);
    delete abdo;
    disconnect();
    clear();
}

void BaseLevel::initScene() {
    setSceneRect(0, 0, getLevelSettings().sceneWidth, getLevelSettings().sceneHeight); // Uses the Level Settings to set the size of the scene.
    setBackgroundBrush(QBrush(QPixmap(getLevelSettings().backgroundImage).scaledToWidth(game->width()))); // Setting Background for scene. TODO: Put this image in Level Settings.

    // Creating the player
    abdo = new Abdo();
    abdo->setPos(200, sceneRect().height() - abdo->boundingRect().height() - 100);
    addItem(abdo);

    // Uses Level Loader to load the level from file instead of creating objects manually.
    QFile mapFile(getLevelSettings().mapFile);
    QFile enemiesFile(getLevelSettings().enemiesFile);
    LevelLoader loader(mapFile, enemiesFile);
    loader.fillScene(this);
}

// Complete the game when you kill the boss
void BaseLevel::killBoss()
{
    isFightingBoss = false;
    isGoodGame = true;
    finishedTime = elapsedTime;
}


void BaseLevel::drawForeground(QPainter *painter, const QRectF &rect)
{
    painter->resetTransform();
    // Draw Winning Screen
    if(isGoodGame) {
        painter->drawRect(sceneRect());
        painter->fillRect(sceneRect(), QColor(0, 0, 0, 120));
        painter->setPen(Qt::white);
        painter->setFont(QFont("Minecraft", 48));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 - 50, "GOOD GAME");

        painter->setFont(QFont("Minecraft", 24));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2, "Coins Collected: " + QString::number(collectedCoins));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 35, "Time spent: " + QString::number(finishedTime / (1000)) + " seconds");

        painter->setFont(QFont("Minecraft", 18));
        painter->drawText(rect.width() / 2 - 200, rect.height() / 2 + 75, "Press Space to continue.");
    }
    // Draw Game Over Screen
    else if(isGameOver) {
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
    // Draw Normal HUD to display hearts and coins collected.
    else {
        // Loop over health and create hearts with offset.
        for (int i = 0; i < health; i++)
        {
            painter->drawPixmap(i * 45 + 10, 25, 40, 40, QPixmap(":/images/heart.png").scaled(40, 40));
        }

        // Display Number of Coins.
        painter->drawPixmap(10, 75, 40, 40, QPixmap(":/images/coin.png").scaled(40, 40));

        painter->setPen(Qt::white);
        painter->setFont(QFont("Minecraft", 24));
        painter->drawText(55, 75 + 30, "x" + QString::number(collectedCoins));

        if(firstTimeGliding) {
            painter->setFont(QFont("Minecraft", 12));
            painter->drawText(game->width() - 450, 50, "Galabeya Glide is unlocked. Try holding space to glide");
        }
        if(firstTimeDoubleJumping) {
            painter->setFont(QFont("Minecraft", 12));
            painter->drawText(game->width() - 450, 80, "Double Jump is unlocked. Try double pressing space");
        }


        // Display Boss Health Bar if we are fighting the boss.
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

        if(isTeleport){
            painter->drawRect(sceneRect());
            painter->fillRect(sceneRect(), QColor(0, 0, 0, 0));
            painter->setPen(Qt::white);
            painter->setFont(QFont("Minecraft", 40));
            painter->drawText(rect.width() / 2 - 215, rect.height() / 2 - 100, "Press [T] to teleport");
        }
    }
}


float BaseLevel::jumpFunction(int time)
{
    // Here is how we can up with it
    // https://www.desmos.com/calculator/pjq0xgis5q
    return -pow((time / jumpWidth) - sqrt(jumpHeight), 2) + jumpHeight;
}

float BaseLevel::fallFunction(int time)
{
    // If glide is enabled, slow down the jump.
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

void BaseLevel::moveHorizontally()
{
    // If you are pressing right and left, don't move
    if (leftPressed && rightPressed)
        return;
    // If you are doing neither, do nothing as well.
    if (!leftPressed && !rightPressed)
        return;

    if(getLevelSettings().teleportStartX != -1){
        if(abdo->x() > getLevelSettings().teleportStartX && abdo->x() < getLevelSettings().teleportEndX && abdo->y() < getLevelSettings().teleportStartY && abdo->y() > getLevelSettings().teleportEndY){
            isTeleport = true;
        }
        else{
            isTeleport = false;
        }
    }

    // If abdo is at the edge of the screen don't move.
    if (abdo->x() <= 0 && leftPressed)
        return;
    if (abdo->x() >= sceneRect().width()-abdo->boundingRect().width() && rightPressed)
        return;

    // If Abdo is blocked by something horizontally don't make him move.
    int direction = 0;
    GroundEntity *blocked = abdo->isBlockedHorizontally(collidingItems, direction); // Direction is passed by reference, so it gets mutated here.

    if (direction == 1 && rightPressed && blocked)
        return;
    if (direction == -1 && leftPressed && blocked)
        return;

    // Move the player in the correct direction. If he is is jumping or falling, slow down his speed.
    abdo->moveBy(speed * (leftPressed ? -1 : 1) * ((isJumping | isFalling) ? speedJumpFactor : 1) * (deltaTime / 1000.0f), 0);
}

void BaseLevel::jumpPlayer()
{
    // This starts of the jump and sets the timeAfterJump the the first deltaTime.
    isJumping = true;
    abdo->moveBy(0, -1);
    timeAfterJump = deltaTime;
    abdo->setState(JUMPING);
}

void BaseLevel::fallPlayer()
{
    // This starts of the falling of the player and sets the timeAfterJump to 0.
    isJumping = false;
    timeAfterJump = 0;
    isFalling = true;
    abdo->setState(FALLING);
}

void BaseLevel::moveVertically()
{
    GroundEntity *ground = abdo->isGrounded(collidingItems);
    // If Abdo is on the ground
    if (ground)
    {
        // Then, he is not falling, and if pressed space, he will jump
        isFalling = false;
        if (spacePressed && !isJumping) {
            jumpPlayer();
            // This will happen only one time isA
            SoundPlayer::abdoJump();
        }
        // If he is on the ground, make sure his position is perfectly on top of the platform, and set default values for when he is not jumping.
        else
        {
            abdo->setPos(abdo->x(), ground->y() + ground->boundingRect().y() - abdo->boundingRect().height());
            isJumping = false;
            timeAfterJump = 0;
            currentJumpCount = 0;
            abdo->setState(IDLE);
        }
    }
    // If Abdo is not on the ground
    else
    {
        // Then If he is jumping
        if (isJumping)
        {
            // Use the jump function to make him move up with deceleration.
            float deltaY = Utils::minMagnitude(jumpFunction(timeAfterJump) - (jumpFunction(timeAfterJump - deltaTime)), TERMINAL_VELOCITY);
            abdo->moveBy(0, -deltaY);
            timeAfterJump += deltaTime;

            // Character is falling now because the gradient is negative
            if (deltaY < 0)
                fallPlayer();

            // Check if something is touching my head, I'll fall so I don't phase through it.
            GroundEntity *ceiling = abdo->isTouchingHead(collidingItems);
            if (ceiling)
                fallPlayer();
        }
        // Here I am probably falling
        else
        {
            // Use the fall function to move down with acceleration.
            float deltaY = Utils::minMagnitude((fallFunction(timeAfterJump) - (timeAfterJump == 0 ? 0 : fallFunction(timeAfterJump - deltaTime))), TERMINAL_VELOCITY);
            abdo->moveBy(0, -deltaY);
            timeAfterJump += deltaTime;
        }
        // If he has fallen down the scene. We game over.
        if(abdo->y() > sceneRect().height() + 50) {
            removeItem(abdo);
            isGameOver = true;
            finishedTime = elapsedTime;
        }
    }
}

// If Abdo touches a coin, we remove the coin and increase the coinsCollected variable.
void BaseLevel::checkCoins()
{
    Coin *coin = abdo->isTouchingCoin(collidingItems);

    if (coin)
    {
        removeItem(coin);
        collectedCoins++;
    }
}

void BaseLevel::checkOil()
{
    Oil *oil = abdo->isTouchingOil(collidingItems);

    if (oil)
    {
        speed = initalSpeed/2;
    }
    else{
        speed = initalSpeed;
    }
}

// Any Harmful Entity Abdo touches, we make abdo take damage.
void BaseLevel::checkEnemies() {
    HarmfulEntity *harmfulEntity = abdo->isTouchingHarmfulEntity(collidingItems);

    if (harmfulEntity)
    {
        // When abdo takes damage the function returns a boolean. If that boolean is true, that means he actually took damage.
        // If it is false, he didn't take damage, this is because we have a timer throttle damage taken by abdo, so he doesn't die instantly.
        if(abdo->takeDamage()){
            SoundPlayer::hitAbdo();
            health -= harmfulEntity->getDamage();
            // If health becomes 0 or less, we game over.
            // if(health <= 0) {
            //     removeItem(abdo);
            //     isGameOver = true;
            //     finishedTime = elapsedTime;
            //     // TODO: Game Over Sound
            // }
        }
    }
}

void BaseLevel::moveEnemies()
{
    QList<QGraphicsItem*> things = items();
    // Loop over all the items in the scene, cast them to a BaseEnemy, and if they are a BaseEnemy, call the move and animate functions of them.
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
    // Loop over all the items in the scene, cast them to a EnemyBullet, and if they are a EnemyBullet, call the move functions of them.
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
    // Checks if Abdo Reached the Location that triggers the boss. If he reached that location, increase his health by two
    // And instantiate the boss.
    if(abdo->x() >= getLevelSettings().triggerBossLoc && !isFightingBoss)
    {
        health += 2;
        boss = newBoss();
        boss->setPos(sceneRect().width() - boss->boundingRect().width()-50, sceneRect().height()-55 - boss->boundingRect().height());
        isFightingBoss = true;
        addItem(boss);
    }
}

// This Function gets called continously
void BaseLevel::gameLoop()
{
    // Retrive the deltaTime (the time between each function call)
    deltaTime = elapsedTimer.restart();
    elapsedTime += deltaTime;
    // This is used to throttle shoot speed.
    timeWhenShot += deltaTime;

    if(!isGameOver && !isGoodGame) {
        // Get Any Items that collide with abdo.
        collidingItems = abdo->collidingItems();
        // Move the player horizontally if he presses the keys.
        moveHorizontally();
        // Move the player vertically if he is not on the ground or pressed space.
        moveVertically();
        // Check if the player touched a coin.
        checkCoins();
        // Check if the player touched oil.
        checkOil();
        // Take Damage from any colliding harmful entity.
        checkEnemies();
        // Spawn Boss If not already spawned when player reaches certain location.
        spawnBoss();
        // Makes the view scroll to make sure the player is always inside the window.
        game->ensureVisible(abdo, 500, 300);
    }

    // Move The Remaining Entities.
    moveBullets();
    moveEnemies();

    update(); // Still Thinking what to do about this.
}

// Handle KeyPresses
void BaseLevel::keyPressEvent(QKeyEvent *event)
{
    if(!isGameOver && !isGoodGame) {
        // For each key press, we set the keyPressed for that key to true
        switch (event->key())
        {
        case Qt::Key_Space: // Jump when space is pressed
            // This allows for double jump if it is enabled.
            if (doubleJumpEnabled && (isJumping || isFalling) && !spacePressed)
            {
                if (currentJumpCount < maxJumps - 1)
                {
                    jumpPlayer();
                    currentJumpCount++;
                    SoundPlayer::doubleJump();
                }
            }
            spacePressed = true;
            break;
        case Qt::Key_Right:
            case Qt::Key_D:
            rightPressed = true;
            // Make Abdo face the right direction
            abdo->setDirection(1);
            break;
        case Qt::Key_Left:
            case Qt::Key_A:
            leftPressed = true;
            // Make Abdo face the left direction
            abdo->setDirection(-1);
            break;
        case Qt::Key_Q:
            // If sound wave (bullet) is enabled, and I am not holding the shoot button, then we can create a new bullet from the player's location
            if (soundWaveEnabled && !shootPressed)
            {
                if(timeWhenShot >= 250) {
                    SoundPlayer::fireSoundWave();
                    SoundWave *s = new SoundWave(abdo->getDirection());
                    s->setPos(abdo->x() + 20 * abdo->getDirection(), abdo->y() + abdo->boundingRect().height() / 4);
                    this->addItem(s);
                    shootPressed = true;
                    timeWhenShot = 0;
                }
            }
            break;
        case Qt::Key_T:
            if(isTeleport){
                abdo->setPos(5200, 900);
                isTeleport = false;
            }
            break;
        case Qt::Key_0:
            emit complete(collectedCoins, finishedTime, getLevelIndex());
            break;
        }
    }
    else if(isGameOver) {
        switch (event->key())
        {
        case Qt::Key_R: // Emit the restart event when R is pressed. This restart event is handled in the Game class
        {
            emit restart();
        }
        break;
        case Qt::Key_Escape: // Emit the quit event when ESC is pressed. This quit event is handled in the Game class
        {
            emit quit();
        }
        break;
        }
    } else if(isGoodGame) {
        switch (event->key())
        {
            case Qt::Key_Space:
            {
                emit complete(collectedCoins, finishedTime, getLevelIndex()); // Emit the complete event when Enter is pressed. This complete event is handled in the Game class
            }
            break;
        }
    }
}

void BaseLevel::keyReleaseEvent(QKeyEvent *event)
{
    if(!isGameOver && !isGoodGame)
        // For each key release, we set the keyPressed for that key to false
        switch (event->key())
        {
        case Qt::Key_Right:
            case Qt::Key_D:
            rightPressed = false;
            break;
        case Qt::Key_Left:
            case Qt::Key_A:
            leftPressed = false;
            break;
        case Qt::Key_Space:
            spacePressed = false;
            break;
        case Qt::Key_Q:
            shootPressed = false;
            break;
        }

}
