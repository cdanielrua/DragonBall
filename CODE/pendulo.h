#ifndef PENDULO_H
#define PENDULO_H

#include <math.h>
#include <QTimer>
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <qdebug.h>
#include <QPixmap>

#define dT 0.005
#define g 9.8

class pendulo: public QObject,public QGraphicsItem
{
    Q_OBJECT
public slots:
    void move();
private:
    QPixmap pixmap;
    double anguloi;//angulo inicial
    double angulo;//angulo
    double vAngulari;//velocidad angular incial
    double vAngular;//velocidad angular
    double aAngular;//aceleracion angular
    double posx;
    double posy;
    int longitud;
    int radio;

public:
    pendulo(double x, double y, int r);
    void calculo();
    void actualizar();
    QTimer *timer;
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);


};

#endif // PENDULO_H
