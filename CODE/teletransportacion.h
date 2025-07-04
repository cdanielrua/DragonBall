#ifndef TELETRANSPORTACION_H
#define TELETRANSPORTACION_H
#include <QGraphicsItem>
#include <QPainter>
#include <QList>

class teletransportacion: public QGraphicsItem
{
public:
    int posx,posy,w,h;
    teletransportacion(int w , int h, int x,int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);
};

#endif // TELETRANSPORTACION_H
