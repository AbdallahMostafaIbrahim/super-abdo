#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QSet>

enum ShopItem {
    DOUBLE_JUMP = 0,
    GALABEYA_GLIDE
};

class GameState
{
public:
    GameState();
    static int coinsCollected;
    static int totalTimeSpendinMs;
    static QSet<ShopItem> itemsBought;
    static QSet<ShopItem> newlyPurchased;
    static int levelReached;
};

#endif // GAMESTATE_H
