#ifndef ESCUDO_H
#define ESCUDO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <math.h>
#include <QPixmap>

#define pi 3.14159265
#define dteta 0.1

class escudo : public QGraphicsItem
{
private:
    int posx;
    int posy;
    double angulo;
    int radio;
    int distancia;
    int centrox, centroy;
public:
    QPixmap pixmap;
    escudo(int _distancia, double _angulo, int _radio);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void move();
    void setCentro(int x, int y);
};

#endif // ESCUDO_H
