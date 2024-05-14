#include "burningtrash.h"

burningTrash::burningTrash() : StaticEnemy(pixmaps){
    int width = 100;
    pixmaps << QPixmap(":/images/Level 3/trash/frame_0_delay-0.07s.png").scaledToWidth(width) << QPixmap(":/images/Level 3/Rapheal/frame_1_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/Level 3/Rapheal/frame_2_delay-0.1s.png").scaledToWidth(width) << QPixmap(":/images/Level 3/Rapheal/frame_3_delay-0.1s.png").scaledToWidth(width);
    currentPixmap = pixmaps[0];
    currentFrame = 0;
}

void burningTrash::animate()
{
    if(animationTimer.elapsed() >= 170) {
        currentPixmap = (pixmaps[currentFrame % pixmaps.size()]);
        currentFrame++;
        animationTimer.restart();
    }
}
