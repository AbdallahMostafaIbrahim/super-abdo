#include "ceilinglight.h"

CeilingLight::CeilingLight(int type) {
    if(type == 0) {
        setPixmap(QPixmap(":/images/office-ceiling-lights.png").scaled(200, 145));
    } else if(type == 1) {
        setPixmap(QPixmap(":/images/level-5/ceiling-light.png").scaledToWidth(100));
    }
}


