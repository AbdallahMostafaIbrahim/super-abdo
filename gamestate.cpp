#include "gamestate.h"

int GameState::coinsCollected = 0;
int GameState::totalTimeSpendinMs = 0;
QSet<ShopItem> GameState::itemsBought = QSet<ShopItem>();
QSet<ShopItem> GameState::newlyPurchased = QSet<ShopItem>();
int GameState::levelReached = 3;

GameState::GameState() {}
