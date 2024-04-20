#ifndef UTILS_H
#define UTILS_H
#include <QFont>
#include<QPainterPath>

class Utils
{
public:
    static float minMagnitude(float l, float r);
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap);
};

#endif // UTILS_H
