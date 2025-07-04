#include "cannon.h"

cannon::cannon(int x, int y, int w, int h)
{
    this->posx=x;
    this->posy=y;
    this->w=w;
    this->h=h;
}

QRectF cannon::boundingRect() const
{
    return QRectF(posx, posy,w,h);
}

void cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/canon.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}
