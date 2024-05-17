#ifndef UTILS_H
#define UTILS_H
#include <QFont>
#include <QList>
#include <QPainterPath>
#include <QPushButton>
#include <QLabel>
#include <QColor>

// Utitlies Class
class Utils
{
public:
    static float minMagnitude(float l, float r);
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap, int precision = 4);
    // static void traverseFrames(QList<QPixmap> &frames, QPixmap &character, int frameRate);
    static QPushButton* createPushButton(QString text, int x, int y, int w, int h, QColor color);
    static QLabel *createLabel(QString text, int x, int y, int w, int h, int size, QColor color);
};

#endif // UTILS_H
