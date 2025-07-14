#ifndef MUROS_H
#define MUROS_H
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <fstream>
#include <QList>

using namespace std;

class muros : public QGraphicsItem
{
public:
    int posx,posy,w,h;
    muros();
    muros(int w , int h, int x,int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget=nullptr);


};
#endif // MUROS_H
