#include "sesion.h"

sesion::sesion(QString _nombre,QString _vida,QString _mun,QString _map)
{
    this->usuario=_nombre;
    this->vida=_vida;
    this->municion=_mun;
    this->mapa=_map;
}

bool sesion::busquedaUsuario( )
{
    leer.open("../textos/usuarios.txt");
    try {
        if(!leer.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No ha leido el archivo"<<endl;
    }
    string linea;
    int separador;
    while(getline(leer,linea)){
        separador=linea.find(',');
        if(usuario==linea.substr(0,separador).c_str()){
            leer.close();
            return true;
        }
    }
    leer.close();
    return false;
}


void sesion::setVida(const QString &newVida)
{
    vida = newVida;
}
