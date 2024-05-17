#ifndef EMPLOYEEENEMY_H
#define EMPLOYEEENEMY_H

#include "movingenemy.h"

class EmployeeEnemy : public MovingEnemy
{
Q_OBJECT
public:
    EmployeeEnemy(int, int, int, int);  //constructor
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    const QPixmap* getPixmap();
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
