#ifndef SOUNDWAVE_H
#define SOUNDWAVE_H

#include <QGraphicsItem>
#include <QObject>

class SoundWave : public QObject, public QGraphicsItem
{
Q_OBJECT
private:
    int dir;
    QPixmap pixmap;
public:
    SoundWave(int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private slots:
    void move();
    void kill();
};

#endif // SOUNDWAVE_H
