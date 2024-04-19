#ifndef UTILS_H
#define UTILS_H
#include <QFont>

class Utils
{
public:
    static float minMagnitude(float l, float r);
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap);
};

#endif // UTILS_H
