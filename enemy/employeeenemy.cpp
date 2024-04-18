#include "employeeenemy.h"
#include <QPainter>
#include <QRectF>

EmployeeEnemy::EmployeeEnemy(int left, int right, int initialPos, int speed) : GroundEnemy(left,right,initialPos,speed) {
    pixmap = QPixmap(":/images/employee-idle.png").scaledToWidth(50);
}

void EmployeeEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap directedPixmap = direction == 1 ? pixmap : pixmap.transformed(QTransform().scale(direction, 1));
    painter->drawPixmap(0, 0, directedPixmap);
}

QRectF EmployeeEnemy::boundingRect() const
{
    return QRectF(0, 0, pixmap.width(), pixmap.height());
}

const QPixmap* EmployeeEnemy::getPixmap()
{
    return &pixmap;
}
