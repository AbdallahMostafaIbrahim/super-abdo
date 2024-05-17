#ifndef SOUNDWAVE_H
#define SOUNDWAVE_H

#include <QGraphicsItem>
#include <QObject>

// Player Bullet
class SoundWave : public QObject, public QGraphicsItem
{
Q_OBJECT
private:
    int dir;
    QPixmap pixmap;
public:
    SoundWave(int);//constructor of soudwave(image and timer)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private slots:
    void move();
    void kill();//kills item it touches and itself
};

#endif // SOUNDWAVE_H
