#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>
#include <QPixmap>

class proyectil : public QObject, public QGraphicsItem
{
    Q_OBJECT
private:
    QPixmap pixmap;
    int direccion;
    int tamano;
    int velocidad;
private slots:
    void move();
    //void moveDown();

public:
    proyectil( int x, int y, int direccion, int _tamano, int _velocidad);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // PROYECTIL_H
