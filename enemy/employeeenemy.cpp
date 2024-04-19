#include "employeeenemy.h"
#include <QPainter>
#include <QRectF>

EmployeeEnemy::EmployeeEnemy(int left, int right, int initialPos, int speed) : GroundEnemy(left, right, initialPos, speed, 3) {
    idle = QPixmap(":/images/employee-idle.png").scaledToWidth(50);
    walking = QPixmap(":/images/employee-walking.png").scaledToWidth(50);
    pixmap = &idle;
    isIdle = true;

    idlePath = QPainterPath();
    QImage image = idle.toImage();
    for (int y = 0; y < image.height(); ++y) {
        for (int x = 0; x < image.width(); ++x) {
            if (image.pixelColor(x, y).alpha() != 0) {  // Check if the pixel is not transparent
                idlePath.addRect(x, y, 1, 1);
            }
        }
    }

    walkingPath = QPainterPath();
    QImage walkingImage = walking.toImage();
    for (int y = 0; y < walkingImage.height(); ++y) {
        for (int x = 0; x < walkingImage.width(); ++x) {
            if (walkingImage.pixelColor(x, y).alpha() != 0) {  // Check if the pixel is not transparent
                walkingPath.addRect(x, y, 1, 1);
            }
        }
    }
}

void EmployeeEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap directedPixmap = direction == 1 ? *pixmap : pixmap->transformed(QTransform().scale(direction, 1));
    painter->drawPixmap(0, 0, directedPixmap);
    if (showDamage) {
        QPainterPath path = isIdle ? idlePath : walkingPath;
        if(direction == -1) {
            QTransform transform = QTransform().scale(direction, 1).translate(-pixmap->width(), 0);
            path = transform.map(path);
        }
        painter->setClipPath(path);
        painter->fillRect(boundingRect(), QColor(255, 0, 0, 69)); // red overlay
    }
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF EmployeeEnemy::boundingRect() const
{
    return QRectF(0, 0, pixmap->width(), pixmap->height());
}

const QPixmap* EmployeeEnemy::getPixmap()
{
    return pixmap;
}

void EmployeeEnemy::animate()
{
    if(isIdle)
        pixmap = &walking;
    else
        pixmap = &idle;

    isIdle = !isIdle;
}
