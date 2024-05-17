#include "utils.h"
#include <cstdlib>
#include <QFontDatabase>
#include <QPainterPath>
#include <QImage>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QElapsedTimer>

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


// void Utils::traverseFrames(QList<QPixmap> &frames, QPixmap &character, int frameRate) {

//     static int currentFrameIndex = 0;
//     static QElapsedTimer timer; // Used to control the frame rate

//     // Check if the timer is not started yet
//     if (!timer.isValid()) {
//         timer.start(); // Start the timer
//     }

//     // Check if enough time has passed since the last frame change
//     if (timer.elapsed() >= frameRate) {
//         // Update the pixmap of the character to the current frame
//         if (currentFrameIndex < frames.size()) {
//             character = frames[currentFrameIndex];
//             ++currentFrameIndex;
//         } else {
//             // If end of frames reached, reset to start
//             currentFrameIndex = 0;
//         }

//         timer.restart(); // Restart the timer for the next frame change
//     }
// }

QPushButton* Utils::createPushButton(QString text, int x, int y, int w, int h, QColor color)
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
        "   background-color: " + color.name() +
        "   ;color: white; "
        "   border-style: solid; "
        "   border-width: 2px; "
        "   border-color: " + color.darker(140).name() +
        "   ;font: bold 14px; "
        "   min-width: 10em; "
        "   padding: 6px; "
        "}"
        "QPushButton:hover {"
        "   background-color: " + color.darker(150).name() +
        ";}"
        "QPushButton:pressed {"
        "   background-color: " + color.darker(170).name() +
        ";}"
        "QPushButton:disabled {"
        "   background-color: " + color.darker(170).name() +
        ";}"
        );

    return button;
}

QLabel *Utils::createLabel(QString text, int x, int y, int w, int h, int size, QColor color)
{
    QLabel* label = new QLabel();
    label->setText(text);
    label->setFont(QFont("Minecraft", size));
    label->setObjectName(QString(text));
    label->setToolTip(text);

    label->setGeometry(x, y, w, h);

    label->setStyleSheet(
        "QLabel {"
        "   color: white ;"
        "   background-color: transparent;"
        "}"
        );

    return label;
}
