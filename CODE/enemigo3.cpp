    #include "enemigo3.h"

enemigo3::enemigo3(int x, int y, int r)
{
    posx=x;
    posy=y;
    radio=r;
    velocidad=2;
    vida=150;
    setPos(posx,posy);
}

void enemigo3::move(int objetivox, int objetivoy)
{
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

QRectF enemigo3::boundingRect() const
{
    return QRectF(-radio,-radio,radio*2,radio*2);
}

void enemigo3::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/cymbal.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
