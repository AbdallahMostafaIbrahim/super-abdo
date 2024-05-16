#ifndef STATICENEMY_H
#define STATICENEMY_H
#include "baseenemy.h"
#include <QPainter>


class StaticEnemy : public BaseEnemy
{ 
public:
    StaticEnemy(QPixmap, int damage = 1);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    void move(int, int) override;
    const QPixmap* getPixmap();
private slots:
    void animate() override;
private:
    QPixmap pixmap;
};

#endif // STATICENEMY_H
