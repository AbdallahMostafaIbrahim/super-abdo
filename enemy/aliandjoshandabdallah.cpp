#include "aliandjoshandabdallah.h"
#include "splinterbullet.h"
#include "karenbullet.h"
#include <QRandomGenerator>
#include <QGraphicsScene>

QList<QPixmap> generateBossPixmaps(int count, const QString& basePath, int width) {
    QList<QPixmap> pixmaps;
    for (int i = 1; i <= count; ++i) {
        QString filePath = QString("%1/frame_%2_delay-0.03s.png").arg(basePath).arg(i, 3, 10, QChar('0'));
        pixmaps.push_back(QPixmap(filePath).scaledToWidth(width));
    }
    return pixmaps;
}

AliAndJoshAndAbdallah::AliAndJoshAndAbdallah() : Boss(generateBossPixmaps(106, ":/images/level-5/baby", 350), 25, 50) {
    bulletTimer.start();
    recoilRate = QRandomGenerator::global()->bounded(1500) + 1000;
    newLoc = QRandomGenerator::global()->bounded(12) + 9;
}

void AliAndJoshAndAbdallah::shoot()
{
    if(bulletTimer.elapsed() > recoilRate)    {
        recoilRate = QRandomGenerator::global()->bounded(1500) + 1000;
        newLoc =  y() + boundingRect().height() - 65 - QRandomGenerator::global()->bounded(50);

        int rando = QRandomGenerator::global()->bounded(2);
        EnemyBullet* bullet;
        if(rando == 1) {
            bullet = new SplinterBullet();
        } else {
            bullet = new KarenBullet();
        }
        bullet->setPos(x(), newLoc);
        scene()->addItem(bullet);
        bulletTimer.restart();
    }
}
