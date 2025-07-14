#include "enemigogiratorio.h"

enemigogiratorio::enemigogiratorio(float PX_, float PY_, float VX_, float VY_, float mass, float R_):escala(0.05)
{
    PX = PX_;
    PY = PY_;
    VX = VX_;
    VY = VY_;
    masa = mass;
    AX = 0;
    AY = 0;
    G = 6.67384*(pow(10,-11));
    R = R_;
}
void enemigogiratorio::acelerar(float px2_, float py2_, float mass2)
{
    radio =pow((pow((px2_-PX),2)+pow((py2_-PY),2)),1/2);
    AX = G*mass2*(px2_-PX)/pow(radio,2);
    AY = G*mass2*(py2_-PY)/pow(radio,2);
}
void enemigogiratorio::actualizar(float dt)
{
    VX = VX + (AX*dt);
    VY = VY + (AY*dt);
    PX = PX + (VX*dt);
    PY = PY + (VY*dt);
    setPos(PX*escala,PY*escala);
}
QRectF enemigogiratorio::boundingRect() const
{
    return QRectF(-1*escala*R,-1*escala*R,2*escala*R,2*escala*R);
}
void enemigogiratorio::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(pintura==0){
        painter->setBrush(Qt::transparent);
    }
    else{
        pixmap.load(":/mapa/imagenes/orbitales.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

    }
}
void enemigogiratorio::setEscala(float s)
{
    escala = s;
}

void enemigogiratorio::setPintura(int value)
{
    pintura=value;
}
