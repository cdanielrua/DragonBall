#include "teletransportacion.h"

teletransportacion::teletransportacion(int w_, int h_, int x, int y)
{
    posx=x;
    posy=y;
    w=w_;
    h=h_;
}

QRectF teletransportacion::boundingRect() const
{
    return QRectF(posx, posy,w,h);
}

void teletransportacion::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(),Qt::transparent);
}
