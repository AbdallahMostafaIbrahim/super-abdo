#include "settingsscene.h"
#include "utils.h"
#include "soundplayer.h"
#include "gamesaver.h"
#include <QGraphicsProxyWidget>

SettingsScene::SettingsScene(Game* game) {
    this->game = game;
    setSceneRect(0,0, game->width(), game->height());

    // Set Background Image
    QBrush bgBrush(QColor(0, 1, 26));
    setBackgroundBrush(bgBrush);

    backButton = Utils::createPushButton("Back", 60, 100, 100, 32, QColor::fromString("#3281a8"));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    addWidget(backButton);

    // This weird workaround is to have a transparent background around the slider. :)
    QWidget* tempWidget = nullptr;
    volumeSlider = Utils::createSlider(100, 400, 0, 100, "volume-slider", tempWidget);
    volumeSlider->setValue((int)(SoundPlayer::volumeFactor * 100));
    addWidget(tempWidget);

    widgets << Utils::createLabel("Volume", 100, 350, 100, 50, 16, QColor::fromString("#fff"))
            << Utils::createLabel("Clear Game Data", 400, 350, 400, 50, 16, QColor::fromString("#fff"));

    clearButton = Utils::createPushButton("Clear", 400, 400, 100, 32, QColor::fromString("#e36334"));
    widgets.append(clearButton);

    for(auto& w: widgets) {
        addWidget(w);
    }


    connect(volumeSlider, &QSlider::valueChanged, this, &SettingsScene::changeVolume);
    connect(clearButton, SIGNAL(clicked()), this, SLOT(clearGameData()));
}

void SettingsScene::clearGameData()
{
    GameSaver::clearState();
}

void SettingsScene::back()
{
    game->goToMainMenu();
}

void SettingsScene::changeVolume()
{
    SoundPlayer::volumeFactor = volumeSlider->value() / 100.0;
}

