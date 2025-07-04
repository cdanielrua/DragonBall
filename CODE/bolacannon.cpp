    #include "bolacannon.h"

bolaCannon::bolaCannon(double x, double y, double v, double ang)
{
    this->posx=x;
    this->posy=y;
    this->vel=v;
    this->ang=ang;
    this->angi=ang;
    this->r=6;
}

QRectF bolaCannon::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r) ;
}

void bolaCannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    pixmap.load(":/mapa/imagenes/balacanon.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void bolaCannon::Mover()
{
    setPos(posx,posy);
}

void bolaCannon::CalcularVelocidad()
{
    if(posy>=350){
        vel_x=vel*cos(ang);
        vel_y=vel*sin(ang)-g*DT;
        vel=sqrt(pow(vel_x,2)+pow(vel_y,2));
        ang=atan2(vel_y,vel_x);
    }
    else {
        ang=angi;
        vel_x=vel*cos(ang);
        vel_y=-vel_y*cr;
        vel=sqrt(pow(vel_x,2)+pow(vel_y,2));
        ang=atan2(vel_y,vel_x);
    }
}

void bolaCannon::CalcularPosicion()
{
    posx=posx+vel_x*DT;
    posy=posy+vel_y*DT-0.5*g*DT*DT;
}
