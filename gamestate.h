#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
    GameState();
    static int coinsCollected;
    static int totalTimeSpendinMs;
    static bool galabeyaGlideBought;
    static bool doubleJumpBought;
    static int levelReached;
};

#endif // GAMESTATE_H
