#include "levelselector.h"
#include "utils.h"
#include "gamestate.h"

LevelSelector::LevelSelector(Game*game) : QGraphicsScene() {
    this->game = game;
    setSceneRect(0,0, game->width(), game->height());

    // Set Background Image
    QBrush bgBrush(QColor(0, 1, 26));
    setBackgroundBrush(bgBrush);

    backButton = Utils::createPushButton("Back", (width() / 2) - 210 / 2, 100, 100, 32, QColor::fromString("#3281a8"));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    addWidget(backButton);
}

void LevelSelector::update() {
    for (auto &button : levelButtons) {
        button->deleteLater();
    }
    levelButtons.clear();

    for (int i = 0; i < 5; ++i) {
        QString buttonLabel = QString("Level ") + QString::number(i + 1);
        QPushButton* button = Utils::createPushButton(buttonLabel, (width() / 2) - 210 / 2, 180 + 80 * i, 100, 32, QColor::fromString("#4CAF50"));
        levelButtons.append(button);
        addWidget(button);
        button->setDisabled(GameState::levelReached <= i);
        connect(button, &QPushButton::clicked, this, [this, i]() {
            new_game(i + 1);
        });
    }
}

void LevelSelector::new_game(int index)
{
    game->startLevel(index);
}


void LevelSelector::back()
{
    game->goToMainMenu();
}

