#include "level1.h"
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <iostream>


Level1::Level1() : QGraphicsScene() {
    // QGraphicsTextItem* text = new QGraphicsTextItem("HEllO");
    // text->setPos(500, 500);
    // this->addItem(text);
    std::cout << "Level1" << std::endl;
}
