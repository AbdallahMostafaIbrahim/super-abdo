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
