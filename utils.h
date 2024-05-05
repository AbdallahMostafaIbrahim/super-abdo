#ifndef UTILS_H
#define UTILS_H
#include <QFont>
#include <QPainterPath>
#include <QPushButton>
#include <QColor>

// Utitlies Class
class Utils
{
public:
    static float minMagnitude(float l, float r);
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap, int precision = 4);
    static QPushButton* createPushButton(QString text, int x, int y, int w, int h, QColor color);
};

#endif // UTILS_H
