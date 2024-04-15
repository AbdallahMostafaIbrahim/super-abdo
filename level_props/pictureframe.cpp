#include "pictureframe.h"

PictureFrame::PictureFrame() {
    setPixmap(QPixmap(":/images/office-picture.png").scaled(200, 145));
}
