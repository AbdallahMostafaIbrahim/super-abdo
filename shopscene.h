#ifndef SHOPSCENE_H
#define SHOPSCENE_H

#include "game.h"
#include "gamestate.h"
#include <QGraphicsScene>
#include <QPushButton>
#include <QList>
#include <map>

struct ItemData {
    QString name;
    int price;
};

class ShopScene : public QGraphicsScene
{
Q_OBJECT
public:
    ShopScene(Game* game);
    void update();
private:
    QList<QWidget*> buyElements;
    Game* game;
    QPushButton* backButton;
    std::map<ShopItem, ItemData> itemToPrice;
private slots:
    void buy(ShopItem);
    void back();
};

#endif // SHOPSCENE_H
