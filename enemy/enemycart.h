#ifndef ENEMYCART_H
#define ENEMYCART_H
#include "movingenemy.h"


class EnemyCart : public MovingEnemy
{
    Q_OBJECT
public:
    EnemyCart(int, int, int, int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    const QPixmap* getPixmap();
    ~EnemyCart();
private:
    QPixmap idle;
    QPixmap walking;
    QPixmap* pixmap;
    QPainterPath idlePath;
    QPainterPath walkingPath;
    bool isIdle;
protected slots:
    void animate() override;
};

#endif // EMPLOYEEENEMY_H
