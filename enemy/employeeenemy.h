#ifndef EMPLOYEEENEMY_H
#define EMPLOYEEENEMY_H

#include "groundenemy.h"

class EmployeeEnemy : public GroundEnemy
{
public:
    EmployeeEnemy(int, int, int, int);
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
    void animate() override;
};

#endif // EMPLOYEEENEMY_H
