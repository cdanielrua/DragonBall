#include "escudo.h"

escudo::escudo(int _distancia, double _angulo,int _radio)
{
    this->distancia=_distancia;
    this->angulo=(_angulo*3.14159265)/180;
    this->posx=distancia*cos(angulo);
    this->posy=distancia*sin(angulo);
    this->radio=_radio;
    setPos(centrox+posx,centroy+posy);
}

QRectF escudo::boundingRect() const
{
    return QRectF(-radio,-radio,radio*2,radio*2);
}

void escudo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/esferadragon.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void escudo::move()
{
    angulo+=dteta;
    if(angulo>=6.2)
        angulo=0;
    posx=distancia*cos(angulo);
    posy=distancia*sin(angulo);
    setPos(centrox+posx,centroy+posy);
}

void escudo::setCentro(int x, int y)
{
    centrox=x;
    centroy=y;
}
