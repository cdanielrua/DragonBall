#ifndef BOLACANNON_H
#define BOLACANNON_H
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QPixmap>

#define DT 0.04
#define g 9.8
#define cr 0.8 //Coficiente de restitucion

class bolaCannon: public QGraphicsItem
{
    int r;
    double vel_x,vel,angi;
public:
    QPixmap pixmap;
    double posx,posy,vel_y,ang;
    bolaCannon(double x, double y, double v, double ang);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem
                                      *option, QWidget *widget = nullptr);
    void Mover();
    void CalcularVelocidad();
    void CalcularPosicion();
};

#endif // BOLACANNON_H
