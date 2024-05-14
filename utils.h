#ifndef UTILS_H
#define UTILS_H
#include <QFont>
#include<QPainterPath>
#include<QList>

// Utitlies Class
class Utils
{
public:
    static float minMagnitude(float l, float r);
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap, int precision = 4);
    // static void traverseFrames(QList<QPixmap> &frames, QPixmap &character, int frameRate);
};

#endif // UTILS_H
