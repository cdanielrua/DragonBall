#include "proyectil.h"

proyectil::proyectil(int x, int y, int _direccion, int _tamano, int _velocidad)
{
    this->tamano=_tamano;
    this->velocidad=_tamano;
    this->direccion=_direccion;
    setPos(x,y);
    QTimer *timer=new QTimer(this);
    //if(direccion==true)
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    //else
    //connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));
    timer->start(50);
}

QRectF proyectil::boundingRect() const
{
    return QRectF(0,0,tamano,tamano);
}

void proyectil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //    painter->setBrush(Qt::black);
    //    painter->drawRect(boundingRect());
    pixmap.load(":/mapa/imagenes/fuegoazul.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void proyectil::move()
{
    switch (direccion) {
    case 1:{
        setPos(x(),y()-velocidad);
        break;
    }
    case 2:{
        setPos(x(),y()+velocidad);
        break;
    }
    case 3:{
        setPos(x()-velocidad,y());
        break;
    }
    case 4:{
        setPos(x()+velocidad,y());
        break;
    }
    }
}
