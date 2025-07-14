#ifndef CANNON_H
#define CANNON_H
#include <muros.h>
#include <QPixmap>

class cannon : public muros
{
public:
    cannon(int x,int y,int w,int h);
    QPixmap pixmap;
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);
};

#endif // CANNON_H
