#include "utils.h"
#include <cstdlib>
#include <QFontDatabase>
#include <QPainterPath>
#include <QImage>
#include <QPixmap>

float Utils::minMagnitude(float l, float r) {
    if(abs(l) < abs(r)) return l;
    else {
        if(l < 0) {
            return -abs(r);
        } else {
            return abs(r);
        }
    }
}

// Creates QPainterPath that is drawn arround the edges of a pixmap. This is used for the red overlay that indicates damage over the pixmaps.
QPainterPath* Utils::createPathFromPixmap(const QPixmap &pixmap, int precision)
{
    QPainterPath *path = new QPainterPath();
    QImage image = pixmap.toImage();
    for (int y = 0; y < image.height(); y += precision) {
        for (int x = 0; x < image.width(); x += precision) {
            if (image.pixelColor(x, y).alpha() != 0) {  // Check if the pixel is not transparent
                path->addRect(x, y, precision, precision);
            }
        }
    }
    return path;
}

QPushButton *Utils::createPushButton(QString text, int x, int y, int w, int h, QString color)
{
    QPushButton* button = new QPushButton();
    button->setText(text);
    button->setObjectName(QString(text));
    button->setToolTip(text);
    button->setGeometry(QRect(x, y, w, h));
    button->setAutoFillBackground(false);
    button->setCursor(Qt::PointingHandCursor);

    button->setStyleSheet(
        "QPushButton {"
        "   background-color: " + color +
        "   ;color: white; "
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: #429646; "
        "   font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: #45A049;" // darker green on hover
        "}"
        "QPushButton:pressed {"
        "   background-color: #397D39;" // Even darker green when pressed
        "}");

    return button;
}
