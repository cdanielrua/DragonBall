#include "muros.h"

muros::muros()
{

}

muros::muros(int w, int h, int x , int y)
{
    this->posx=x;
    this->posy=y;
    this->w=w;
    this->h=h;

}
QRectF muros::boundingRect() const{
    return QRectF(posx, posy,w,h);
}
void muros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->fillRect(boundingRect(),Qt::transparent  );
}
