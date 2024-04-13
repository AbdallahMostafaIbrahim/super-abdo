#ifndef SOUNDWAVE_H
#define SOUNDWAVE_H
#include"platform.h"
#include<QObject>

class SoundWave : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    int dir;
 public:
    SoundWave(int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
public slots:
    void move();
    void byebye();
};

#endif // SOUNDWAVE_H
