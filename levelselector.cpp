#include "levelselector.h"

LevelSelector::LevelSelector(Game*game) : QGraphicsScene() {
    this->game = game;
    this->setSceneRect(0,0, game->width(), game->height());

    // Set Background Image
    QBrush bgBrush(QColor(0, 1, 26));
    this->setBackgroundBrush(bgBrush);

    // Create the buttons
    Level_1 = new QPushButton();
    Level_1->setText("Level 1");
    Level_1->setObjectName(QString("Level_1"));
    Level_1->setToolTip("Level 1");
    Level_1->setGeometry(QRect((this->width() / 2) - 210 / 2, 180, 100, 32));
    Level_1->setAutoFillBackground(false);
    Level_1->setCursor(Qt::PointingHandCursor);

    Level_1->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50; " // Green background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");



    Level_2 = new QPushButton();
    Level_2->setText("Level 2");
    Level_2->setObjectName(QString("Level_2"));
    Level_2->setToolTip("Level 2");
    Level_2->setGeometry(QRect((this->width() / 2) - 210 / 2, 260, 100, 32));
    Level_2->setAutoFillBackground(false);
    Level_2->setCursor(Qt::PointingHandCursor);

    Level_2->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50; " // Green background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");


    Level_3 = new QPushButton();
    Level_3->setText("Level 3");
    Level_3->setObjectName(QString("Level_3"));
    Level_3->setToolTip("Level 3");
    Level_3->setGeometry(QRect((this->width() / 2) - 210 / 2, 340, 100, 32));
    Level_3->setAutoFillBackground(false);
    Level_3->setCursor(Qt::PointingHandCursor);

    Level_3->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50; " // Green background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");


    Level_4 = new QPushButton();
    Level_4->setText("Level 4");
    Level_4->setObjectName(QString("Level_4"));
    Level_4->setToolTip("Level 4");
    Level_4->setGeometry(QRect((this->width() / 2) - 210 / 2, 420, 100, 32));
    Level_4->setAutoFillBackground(false);
    Level_4->setCursor(Qt::PointingHandCursor);

    Level_4->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50; " // Green background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");


    Level_5 = new QPushButton();
    Level_5->setText("Level 5");
    Level_5->setObjectName(QString("Level_5"));
    Level_5->setToolTip("Level 5");
    Level_5->setGeometry(QRect((this->width() / 2) - 210 / 2, 500, 100, 32));
    Level_5->setAutoFillBackground(false);
    Level_5->setCursor(Qt::PointingHandCursor);

    Level_5->setStyleSheet(
        "QPushButton {"
        "   background-color: #4CAF50; " // Green background
        "   color: white; "              // White text
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");

    // Add Buttons to Scene
    addWidget(Level_1);
    addWidget(Level_2);
    addWidget(Level_3);
    addWidget(Level_4);
    addWidget(Level_5);


    // Event Handlers
    // TODO: Make this better somehow using one function. probably just give the slot a parameter.
    connect(Level_1, SIGNAL(clicked()), this, SLOT(new_game_1()));
    connect(Level_2, SIGNAL(clicked()), this, SLOT(new_game_2()));
    connect(Level_3, SIGNAL(clicked()), this, SLOT(new_game_3()));
    connect(Level_4, SIGNAL(clicked()), this, SLOT(new_game_4()));
    connect(Level_5, SIGNAL(clicked()), this, SLOT(new_game_5()));

}

void LevelSelector::new_game_1()
{
    game->startLevel(1);
}

void LevelSelector::new_game_2()
{
    game->startLevel(2);
}
void LevelSelector::new_game_3()
{
    game->startLevel(3);
}
void LevelSelector::new_game_4()
{
    game->startLevel(4);
}
void LevelSelector::new_game_5()
{
    game->startLevel(5);
}
