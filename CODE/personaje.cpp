#include "personaje.h"


int personaje::getMapa() const
{
    return mapa;
}

void personaje::setMapa(int newMapa)
{
    mapa = newMapa;
}

int personaje::getMunicion() const
{
    return municion;
}

void personaje::setMunicion(int newMunicion)
{
    municion = newMunicion;
}

int personaje::getVida() const
{
    return vida;
}

void personaje::setVida(int newVida)
{
    vida = newVida;
}

personaje::personaje()
{

}

personaje::personaje(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=3;
    setPos(posx,posy);
    this->vida=100;
    this->municion=15;
    this->mapa=0;
    timer=new QTimer();

    filas=0;
    columnas=0;
    pixmap=new QPixmap(":/mapa/imagenes/personaje3.png");
    //dimensiones de cada imagen
    ancho = 10;
    alto = 20;

}

QRectF personaje::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,filas,ancho,alto);

}

void personaje::moveRight()
{
    this->posx+=velocidad;
    filas=20;
    columnas+=10;
    if(columnas>=30) columnas=0;
    setPos(posx,posy);
}

void personaje::moveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
    filas=60;
    columnas+=10;
    if(columnas>=30) columnas=0;
}

void personaje::moveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);
    filas=40;
    columnas+=10;
    if(columnas>=30) columnas=0;
}

void personaje::moveDown()
{
    this->posy+=velocidad;
    columnas+=10;
    filas=0;
    if(columnas>=30) columnas=0;
    setPos(posx,posy);
}
