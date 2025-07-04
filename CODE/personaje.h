#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPixmap>

class personaje : public QGraphicsItem, public QObject
{
public:
    int radio,velocidad,vida,municion,mapa,posx,posy;
    personaje();
    QPixmap *pixmap;
    QTimer *timer;
    float filas, columnas,ancho, alto;
    personaje(int x, int y, int r);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    int getVida() const;
    void setVida(int newVida);
    int getMunicion() const;
    void setMunicion(int newMunicion);
    int getMapa() const;
    void setMapa(int newMapa);
};

#endif // PERSONAJE_H
