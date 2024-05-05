#include "levelselector.h"
#include "utils.h"
#include "gamestate.h"

LevelSelector::LevelSelector(Game*game) : QGraphicsScene() {
    this->game = game;
    this->setSceneRect(0,0, game->width(), game->height());

    // Set Background Image
    QBrush bgBrush(QColor(0, 1, 26));
    this->setBackgroundBrush(bgBrush);

    // Create the buttons
    levelButtons << Utils::createPushButton("Level 1", (width() / 2) - 210 / 2, 180, 100, 32, "#4CAF50")
                 << Utils::createPushButton("Level 2", (width() / 2) - 210 / 2, 260, 100, 32, "#4CAF50")
                 << Utils::createPushButton("Level 3", (width() / 2) - 210 / 2, 340, 100, 32, "#4CAF50")
                 << Utils::createPushButton("Level 4", (width() / 2) - 210 / 2, 420, 100, 32, "#4CAF50")
                 << Utils::createPushButton("Level 5", (width() / 2) - 210 / 2, 500, 100, 32, "#4CAF50");

    QPushButton* backButton = Utils::createPushButton("Back", (width() / 2) - 210 / 2, 100, 100, 32, "#3281a8");

    // Add Buttons to Scene with their corresponding event handler
    for(int i = 0; i < levelButtons.size(); i++) {
        if(GameState::levelReached < i + 1) {
            levelButtons[i]->setDisabled(true);
        }
        addWidget(levelButtons[i]);
        connect(levelButtons[i], &QPushButton::clicked, this, [this, i]() {
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

