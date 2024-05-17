#ifndef UTILS_H
#define UTILS_H
#include <QFont>
#include <QList>
#include <QPainterPath>
#include <QPushButton>
#include <QLabel>
#include <QColor>
#include <QSlider>

// Utitlies Class
class Utils
{
public:
    static float minMagnitude(float l, float r);//returns the minimum magnitude  of 2 floats
    static QPainterPath* createPathFromPixmap(const QPixmap &pixmap, int precision = 4);// Creates QPainterPath that is drawn arround the edges of a pixmap
    // static void traverseFrames(QList<QPixmap> &frames, QPixmap &character, int frameRate);
    static QPushButton* createPushButton(QString text, int x, int y, int w, int h, QColor color);//function to create push button easily
    static QLabel *createLabel(QString text, int x, int y, int w, int h, int size, QColor color);//function to create label  easily
    static QSlider *createSlider(int x, int y, int min, int max, QString tooltip, QWidget*&);//makes volume sloder for example
};

#endif // UTILS_H
