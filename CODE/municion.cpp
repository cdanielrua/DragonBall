#include "municion.h"

municion::municion(int x, int y, int w, int h)
{
    this->posx=x;
    this->posy=y;
    this->w=w;
    this->h=h;
}

QRectF municion::boundingRect() const
{
    return QRectF(posx, posy,w,h);
}

void municion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/cajaammno.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}
