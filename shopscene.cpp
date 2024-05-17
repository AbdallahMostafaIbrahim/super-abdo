#include "shopscene.h"
#include "utils.h"

ShopScene::ShopScene(Game *game) : QGraphicsScene()
{
    this->game = game;

    setSceneRect(0,0, game->width(), game->height());

    itemToPrice.insert({ ShopItem::GALABEYA_GLIDE, { QString("Galabeya Glide"), 15 } });
    itemToPrice.insert({ ShopItem::DOUBLE_JUMP, { QString("Double Jump"), 30 } });
    itemToPrice.insert({ ShopItem::EXTRA_HEART, { QString("Extra Heart"), 30 } });


    // Set Background Image
    QBrush bgBrush(QColor(0, 1, 26));
    setBackgroundBrush(bgBrush);

    backButton = Utils::createPushButton("Back", 60, 100, 100, 32, QColor::fromString("#3281a8"));
    connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
    addWidget(backButton);

    update();
}

void ShopScene::update()
{
    for (auto &button : buyElements) {
        button->deleteLater();
    }
    buyElements.clear();

    int i = 0;
    for (auto& iter: itemToPrice) {
        int price = iter.second.price;
        QString labelText = iter.second.name ;

        bool canAfford = GameState::coinsCollected >= price;
        bool alreadyHasIt = GameState::itemsBought.contains(iter.first);

        if(alreadyHasIt) {
            labelText += "(owned)";
        } else {
            labelText += "(" + QString::number(price) + " coins)";
        }

        QLabel* label = Utils::createLabel(labelText, 200 + i * 300, 300, 300, 30, 12, QColor::fromString("#fffff"));
        QPushButton* button = Utils::createPushButton("BUY", 200 + i * 300, 350, 100, 32, QColor::fromString("#4CAF50"));
        buyElements.append(button);
        buyElements.append(label);
        addWidget(button);
        addWidget(label);

        button->setDisabled(alreadyHasIt || !canAfford);

        connect(button, &QPushButton::clicked, this, [this, iter]() {
            buy(iter.first);
        });

        i++;
    }

    QLabel* coinsLabel = Utils::createLabel(QString::number(GameState::coinsCollected) + " coins", width() - 350, 100, 300, 60, 18, QColor::fromString("#fffff"));
    addWidget(coinsLabel);
    buyElements.append(coinsLabel);
}


void ShopScene::buy(ShopItem item)
{
    auto iter = itemToPrice.find(item);
    if(iter != itemToPrice.end()) {
        int price = iter->second.price;
        if(GameState::coinsCollected >= price) {
            GameState::coinsCollected -= price;
            GameState::itemsBought.insert(item);
            GameState::newlyPurchased.insert(item);
        }
    }
    update();
}

void ShopScene::back()
{
    game->goToMainMenu();
}
