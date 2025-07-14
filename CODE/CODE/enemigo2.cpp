#include "enemigo2.h"

enemigo2::enemigo2(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    velocidad=2;
    vida=20;
    setPos(posx,posy);
    posxInicial=x;
    posyInicial=y;
}

void enemigo2::move(int objetivox, int objetivoy, bool colision)
{
    if(colision==false){
        if(x()<objetivox)
            posx+=velocidad;
        else if(x()>objetivox)
            posx-=velocidad;

        if(y()<objetivoy)
            posy+=velocidad;
        else if(y()>objetivoy)
            posy-=velocidad;

        setPos(posx,posy);
    }
    else {
        posx=posxInicial;
        posy=posyInicial;
        setPos(posx,posy);
    }
}

QRectF enemigo2::boundingRect() const
{
    return QRectF(-radio,-radio,radio*2,radio*2);
}

void enemigo2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/piccolo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
