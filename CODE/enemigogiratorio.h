#ifndef ENEMIGOGIRATORIO_H
#define ENEMIGOGIRATORIO_H
#include <QPainter>
#include <math.h>
#include <cmath>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>

class enemigogiratorio: public QGraphicsItem
{
private:
    QPixmap pixmap;
    float escala;

public:
    enemigogiratorio(float PX_,float PY_,float VX_,float VY_,float mass, float R_);
    void acelerar(float px2_,float py2_, float mass2);
    void actualizar(float dt);
    float PX;
    float PY;
    float VX;
    float VY;
    float radio; //distancia entre 2 planetas
    float masa;
    float AX;
    float AY;
    float G;
    float R;//Radio de un planeta

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setEscala(float s);
    int pintura=0;
    void setPintura(int value);
};

#endif // ENEMIGOGIRATORIO_H
