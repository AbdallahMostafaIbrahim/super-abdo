#ifndef UTILS_H
#define UTILS_H
#include <QFont>
#include<QPainterPath>

class Utils
{
public:
    static float minMagnitude(float l, float r);
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap, int precision = 4);
};

#endif // UTILS_H
