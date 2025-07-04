#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    multiplayer=new QGraphicsScene();
    mapaEscena=new QGraphicsScene();

    // (Opcional, para depuración de rutas)
    qDebug() << "Current working directory:" << QDir::currentPath();

    //manipulacion de Menu
    ui->graphicsView->hide();
    ui->USER->hide();
    ui->L_usuario->hide();
    ui->REGISTER->hide();
    ui->reintentar->hide();
    ui->ocupado->hide();
    ui->Start->hide();
    ui->reintentar_2->hide();
    ui->ocupado_2->hide();
    ui->vidaT->hide();
    ui->graphicsView->setScene(mapaEscena);
    mapaEscena->setSceneRect(0,0,960,960);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    tulio=new personaje(340,390,8);
    mapaEscena->addItem(tulio);

    ui->graphicsView->scale(2.5,2.5);

    crearEnemigos1(rutaEnemigos1_1);
    crear_muros();
    crearMuniciones();

    //mapa
    mapaEscena->setBackgroundBrush(QBrush(QImage(":/mapa/imagenes/mapa.png")));
    //tps
    pasar.append(new teletransportacion(16,10,450,17));
    mapaEscena->addItem(pasar.back());
    pasar.append(new teletransportacion(10,16,550,445));
    mapaEscena->addItem(pasar.back());

    cargarNivel1();

    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(nivel1()));
    timer1->start(100);

    timer2=new QTimer(this);
    timer2->start(100); // INICIAR TIMER2
    connect(timer2,SIGNAL(timeout()),this,SLOT(actualizar()));

    timerMultiPlayer=new QTimer(this);
    timerMultiPlayer->stop();
    connect(timerMultiPlayer,SIGNAL(timeout()),this,SLOT(colisionMultiplayer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUser(const QString &newUser)
{
    User = newUser;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(iniciaMulti==false){
        if(evento->key()==Qt::Key_D)
        {
            tulio->moveRight();
            ui->graphicsView->centerOn(tulio);
            if(EvaluarColision(tulio))tulio->moveLeft();
            moverMapa();
        }
        else if(evento->key()==Qt::Key_A)
        {
            tulio->moveLeft();
            ui->graphicsView->centerOn(tulio);
            if(EvaluarColision(tulio))tulio->moveRight();
            moverMapa();

        }
        else if(evento->key()==Qt::Key_W)
        {
            tulio->moveUp();
            ui->graphicsView->centerOn(tulio);
            if(EvaluarColision(tulio))tulio->moveDown();
            moverMapa();

        }
        else if(evento->key()==Qt::Key_S)
        {
            tulio->moveDown();
            ui->graphicsView->centerOn(tulio);
            if(EvaluarColision(tulio))tulio->moveUp();
            moverMapa();

        }
        else if(evento->key()==Qt::Key_I and tulio->municion>0)
        {
            //creando proyectil
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,1,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
        else if(evento->key()==Qt::Key_K and tulio->municion>0)
        {
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,2,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
        else if(evento->key()==Qt::Key_J and tulio->municion>0)
        {
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,3,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
        else if(evento->key()==Qt::Key_L and tulio->municion>0)
        {
            balasPersonaje.push_back(new proyectil(tulio->posx, tulio->posy,4,5,4));
            mapaEscena->addItem(balasPersonaje.back());
            tulio->municion-=1;
        }
    }
    else{
        //Jugador1 movimiento---------------------------------------------
        if(evento->key()==Qt::Key_W)
        {
            jugador1->moveUp();
        }
        else if(evento->key()==Qt::Key_S)
        {
            jugador1->moveDown();
        }
        else if(evento->key()==Qt::Key_A)
        {
            jugador1->moveLeft();
        }
        else if(evento->key()==Qt::Key_D)
        {
            jugador1->moveRight();
        }
        else if(evento->key()==Qt::Key_H){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,4,
                                                  15,8));
            multiplayer->addItem(balasJugador1.back());
        }
        else if(evento->key()==Qt::Key_F){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,3,
                                                  15,8));
            multiplayer->addItem(balasJugador1.back());
        }
        else if(evento->key()==Qt::Key_G){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,2,
                                                  15,8));
            multiplayer->addItem(balasJugador1.back());
        }
        else if(evento->key()==Qt::Key_T){
            balasJugador1.push_back(new proyectil(jugador1->posx,jugador1->posy,1,
                                                  15,8));
            multiplayer->addItem(balasJugador1.back());
        }


        //Jugador2 movimiento ---------------------------------------------------
        else if(evento->key()==Qt::Key_5)
        {
            jugador2->moveUp();
        }
        else if(evento->key()==Qt::Key_2)
        {
            jugador2->moveDown();
        }
        else if(evento->key()==Qt::Key_1)
        {
            jugador2->moveLeft();
        }
        else if(evento->key()==Qt::Key_3)
        {
            jugador2->moveRight();
        }
        else if(evento->key()==Qt::Key_L){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,4,
                                                  15,8));
            multiplayer->addItem(balasJugador2.back());
        }
        else if(evento->key()==Qt::Key_J){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,3,
                                                  15,8));
            multiplayer->addItem(balasJugador2.back());
        }
        else if(evento->key()==Qt::Key_K){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,2,
                                                  15,8));
            multiplayer->addItem(balasJugador2.back());
        }
        else if(evento->key()==Qt::Key_I){
            balasJugador2.push_back(new proyectil(jugador2->posx,jugador2->posy,1,
                                                  15,8));
            multiplayer->addItem(balasJugador2.back());
        }
    }
}

void MainWindow::crear_muros()
{
    {
        // CAMBIO AQUÍ: Elimina "../" de la ruta
        leer.open("textos/muros.txt");
        try {
            if(!leer.is_open())
                throw '1';
            else
                throw '2';
        }  catch (char c) {
            if(c=='1')
                cout<<"No lo lee";
        }
        string linea;
        while(getline(leer, linea)){
            string pedazoLinea;
            short int valores[4];
            int tramo=0;
            for(int i=0;i<4;i++){
                if(i<3){
                    tramo=linea.find(',');
                    pedazoLinea=linea.substr(0,tramo);
                    valores[i]=atoi(pedazoLinea.c_str());
                    linea=linea.substr(tramo+1);
                }
                else
                    valores[i]=atoi(linea.c_str());
            }
            paredes.push_back(new muros(valores[0],valores[1],valores[2],valores[3]));
            mapaEscena->addItem(paredes.back());
        }
        leer.close();
    }
}

void MainWindow::crearMuniciones()
{
    {

        leer.open("textos/municiones.txt");
        try {
            if(!leer.is_open())
                throw '1';
            else
                throw '2';
        }  catch (char c) {
            if(c=='1')
                cout<<"No lo lee";
        }
        string linea;
        while(getline(leer, linea)){
            string pedazoLinea;
            short int valores[4];
            int tramo=0;
            for(int i=0;i<4;i++){
                if(i<3){
                    tramo=linea.find(',');
                    pedazoLinea=linea.substr(0,tramo);
                    valores[i]=atoi(pedazoLinea.c_str());
                    linea=linea.substr(tramo+1);
                }
                else
                    valores[i]=atoi(linea.c_str());
            }
            recarga.push_back(new municion(valores[0],valores[1],valores[2],valores[3]));
            mapaEscena->addItem(recarga.back());
        }
        leer.close();
    }
}


void MainWindow::crearEnemigos1(string ruta)
{
    string linea;
    ifstream leer;
    int x,y,r,dirMov,dirDisp;
    string valor;
    int pos, pos_inicial;

    leer.open(ruta);

    if (!leer.is_open()) {
        qDebug() << "Error: No se pudo abrir el archivo de enemigos en la ruta: " << QString::fromStdString(ruta);
        return;
    }

    while(getline(leer,linea)){
        pos_inicial=0;
        pos=linea.find(',');
        valor=linea.substr(pos_inicial,pos);
        x=stoi(valor);

        pos_inicial=pos+1;
        pos=linea.find(',',pos_inicial);
        valor=linea.substr(pos_inicial,pos-pos_inicial);
        y=stoi(valor);

        pos_inicial=pos+1;
        pos=linea.find(',',pos_inicial);
        valor=linea.substr(pos_inicial,pos-pos_inicial);
        r=stoi(valor);

        pos_inicial=pos+1;
        pos=linea.find(',',pos_inicial);
        valor=linea.substr(pos_inicial,pos-pos_inicial);
        dirMov=stoi(valor);

        pos_inicial=pos+1;
        pos=linea.find(',',pos_inicial);
        valor=linea.substr(pos_inicial,pos-pos_inicial);
        dirDisp=stoi(valor);

        goku.push_back(new enemigo1(x,y,r,dirMov,dirDisp));
    }
    leer.close();
    // Añadir a la escena los enemigos creados. Este bucle es crucial.
    for(itEnemigos1 = goku.begin(); itEnemigos1 != goku.end(); itEnemigos1++){
        mapaEscena->addItem(*itEnemigos1);
    }
}

void MainWindow::autoguardado()
{
    // CAMBIO AQUÍ: Elimina "../" de las rutas
    leer.open("textos/usuarios.txt");
    Temp.open("textos/Temp.txt");
    try {
        if(!Temp.is_open() || !leer.is_open())
            throw '1';
    }  catch (char c) {
        if(c=='1')
            cout<<"No ha leido el archivo"<<endl;
    }
    string linea,cambio;
    while(getline(leer, linea)){
        string pedazoLinea,valores[4];
        int tramo=0;
        tramo=linea.find(',');
        if(User==linea.substr(0,tramo).c_str() ){
            cuenta=new sesion(User,QVariant(tulio->getVida()).toString(),QVariant(tulio->getMunicion()).toString(),QVariant(tulio->getMapa()).toString());
            Temp<<cuenta->usuario.toStdString()<<","<<cuenta->vida.toStdString()<<","<<cuenta->municion.toStdString()<<","<<cuenta->mapa.toStdString()<<endl;
        }
        else{
            Temp<<linea<<endl;
        }
    }
    leer.close();
    Temp.close();
    remove("textos/usuarios.txt"); // CAMBIO AQUÍ: Elimina "../"
    rename("textos/Temp.txt","textos/usuarios.txt"); // CAMBIO AQUÍ: Elimina "../"
}

void MainWindow::cargarNivel1()
{
    nivelActual=1;
    trampa1= new pendulo(200,100,5);
    mapaEscena->addItem(trampa1);
}

void MainWindow::cargarNivel2()
{
    nivelActual=2;
    trampa1->timer->stop();
    // Limpia la lista de goku antes de cargar un nuevo nivel.
    for(itEnemigos1=goku.begin();itEnemigos1!=goku.end();){
        mapaEscena->removeItem(*itEnemigos1);
        delete *itEnemigos1;
        itEnemigos1 = goku.erase(itEnemigos1);
    }
    timerProyectilEnemigo=0;
    //Creacion movimiento parabolico
    crearEnemigos1(rutaEnemigos1_2); // Carga los enemigos del nivel 2.
    cannon1=new cannon(635,350,20,20);
    mapaEscena->addItem(cannon1);
    bolasCannon.push_back(new bolaCannon(650,350,30,(45*3.141598)/180));
    mapaEscena->addItem(bolasCannon.back());
    piccolo.push_back(new enemigo2(670,40,8));
    mapaEscena->addItem(piccolo.back());
    piccolo.push_back(new enemigo2(670,140,8));
    mapaEscena->addItem(piccolo.back());
}

void MainWindow::cargarNivel3()
{
    nivelActual=3;
    // Limpia las listas de enemigos de niveles anteriores.
    for(itEnemigos1=goku.begin();itEnemigos1!=goku.end();){
        mapaEscena->removeItem(*itEnemigos1);
        delete *itEnemigos1;
        itEnemigos1 = goku.erase(itEnemigos1);
    }
    // Asegúrate de limpiar también otras listas de enemigos si pasas de nivel.
    for(itEnemigos2=piccolo.begin();itEnemigos2!=piccolo.end();){
        mapaEscena->removeItem(*itEnemigos2);
        delete *itEnemigos2;
        itEnemigos2 = piccolo.erase(itEnemigos2);
    }
    // Para las bolas de cañón, asegúrate de limpiarlas también.
    for(list<bolaCannon *>::iterator itBC = bolasCannon.begin(); itBC != bolasCannon.end(); ){
        mapaEscena->removeItem(*itBC);
        delete *itBC;
        itBC = bolasCannon.erase(itBC);
    }
    if (cannon1) { // Si existe el cañón, quítalo de la escena y elimínalo
        mapaEscena->removeItem(cannon1);
        delete cannon1;
        cannon1 = nullptr;
    }

    timerProyectilEnemigo=0;
    //Creacion movimiento gravitacional
    orbital.append(new enemigogiratorio(9500,15500,0,0,70000,200));
    mapaEscena->addItem(orbital.back());
    orbital.append(new enemigogiratorio(4500,15500,0,-1,70,160));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    orbital.append(new enemigogiratorio(14500,15500,0,1,700,170));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    orbital.append(new enemigogiratorio(9500,20500,-1,0,70,180));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    orbital.append(new enemigogiratorio(9500,10500,1,0,70,190));
    mapaEscena->addItem(orbital.back());
    orbital.back()->setPintura(1);
    dt=10;
    timer2->start(100);
    //Creacion cymbal
    cymbal=new enemigo3(475,775,10);
    mapaEscena->addItem(cymbal);
    //Creacion Escudo cymbal
    for(int i=0;i<12;i++) {
        orbes.push_back(new escudo(50,i*30,10));
        escudo * punteroOrbes=orbes.back();
        punteroOrbes->setCentro(cymbal->posx,cymbal->posy);
        mapaEscena->addItem(orbes.back());
    }
    crearEnemigos1(rutaEnemigos1_3);
}

void MainWindow::moverMapa()
{
    if(pasar[0]->collidesWithItem(tulio)){
        tulio->setPos(900,70);
        tulio->posx=900;
        tulio->posy=70;
        tulio->setMapa(1);
        autoguardado();
        cargarNivel2();
    }
    if(pasar[1]->collidesWithItem(tulio)){
        tulio->setPos(20,620);
        tulio->posx=20;
        tulio->posy=620;
        tulio->setMapa(2);
        autoguardado();
        cargarNivel3();
    }
}

void MainWindow::nivel1()
{
    ui->vidaT->setText(QString::number(tulio->vida));
    if(nivelActual==1){
        if((trampa1)->collidesWithItem(tulio)){
            QApplication::quit();
        }

    }
    else if(nivelActual==2){
        //Funcionamiento tiro parabolico
        for(int i=0;i<10;i++){
            bolasCannon.back()->CalcularVelocidad();
            bolasCannon.back()->CalcularPosicion();
            bolasCannon.back()->Mover();
            timerBolaCannon+=1;
            if(timerBolaCannon==500){
                mapaEscena->removeItem(bolasCannon.back());
                list<bolaCannon *>::iterator it;
                it=bolasCannon.begin();
                bolasCannon.erase(it);
                bolasCannon.push_back(new bolaCannon(650,350,30,(45*3.141598)/180));
                mapaEscena->addItem(bolasCannon.back());
                timerBolaCannon=0;
            }
        }
        //Colision bola cannon
        if(bolasCannon.back()->collidesWithItem(tulio))
            QApplication::quit();
        //Colisiones
        for(itEnemigos2=piccolo.begin();itEnemigos2!=piccolo.end();){
            if(tulio->collidesWithItem(*itEnemigos2))
                tulio->vida-=20;
            enemigo2 * punteroEnemigo2= *itEnemigos2;
            for(it=balasPersonaje.begin();it!=balasPersonaje.end();){
                if(punteroEnemigo2->collidesWithItem(*it)){
                    punteroEnemigo2->vida-=10;
                    mapaEscena->removeItem(*it);
                    delete *it;
                    it = balasPersonaje.erase(it);
                    continue;
                }
                ++it;
            }
            if(punteroEnemigo2->vida<=0){
                mapaEscena->removeItem(*itEnemigos2);
                delete *itEnemigos2;
                itEnemigos2 = piccolo.erase(itEnemigos2);
            } else {
                ++itEnemigos2;
            }
        }
    }
    else if(nivelActual==3){
        for(itOrbital=orbital.begin();itOrbital!=orbital.end();itOrbital++){
            if(tulio->collidesWithItem(*itOrbital))
                QApplication::quit();
        }
        cymbal->move(tulio->x(),tulio->y());
        //Colisiones orbes con personaje
        for(itOrbes=orbes.begin();itOrbes!=orbes.end();){
            if(cymbal->vida<=70){
                mapaEscena->removeItem(*itOrbes);
                delete *itOrbes;
                itOrbes = orbes.erase(itOrbes);
                continue;
            }
            else{
                escudo * punteroOrbes=*itOrbes;
                punteroOrbes->setCentro(cymbal->posx,cymbal->posy);
                punteroOrbes->move();
                if(tulio->collidesWithItem(*itOrbes))
                    tulio->vida-=1;
            }
            ++itOrbes;
        }
        //colision balas
        for(it=balasPersonaje.begin();it!=balasPersonaje.end();){
            proyectil *punteroBalas=*it;
            if(punteroBalas->collidesWithItem(cymbal)){
                mapaEscena->removeItem(*it);
                delete *it;
                it = balasPersonaje.erase(it);
                cymbal->vida-=10;
                continue;
            }
            ++it;
        }
        if(cymbal->collidesWithItem(tulio)){
            QApplication::quit();
        }
        if(cymbal->vida<=0){
            QApplication::quit();
        }
    }

    //Finalizacion del juego
    if(tulio->vida<=0)
        QApplication::quit();

    //Recoger municion-----------------------------------------------------------------
    list<municion *>:: iterator itMunicion;
    for(itMunicion=recarga.begin();itMunicion!=recarga.end();){
        if((*itMunicion)->collidesWithItem(tulio)){
            mapaEscena->removeItem(*itMunicion);
            delete *itMunicion;
            itMunicion = recarga.erase(itMunicion);
            tulio->municion+=15;
            continue;
        }
        ++itMunicion;
    }
    //----------------------------------------------------------------------------------


    //Colisiones enemigo2----------------------------------------------------------------
    //Con muros
    int enemigo2Parar=0;
    for(itEnemigos2=piccolo.begin();itEnemigos2!=piccolo.end();itEnemigos2++){
        enemigo2 * punteroEnemigo2=*itEnemigos2;
        if(EvaluarColision(*itEnemigos2))
            enemigo2Parar=1;
        else
            enemigo2Parar=2;
        switch (enemigo2Parar) {
        case 1:{
            punteroEnemigo2->move(tulio->posx,tulio->posy,true);
            break;
        }
        case 2:{
            punteroEnemigo2->move(tulio->posx,tulio->posy,false);
            break;
        }
        }
    }

    //-----------------------------------------------------------------------------------
}

template <typename tipo>
bool MainWindow::EvaluarColision(tipo *objeto)//Sirve para evaluar colisiones con los muros.
{

    for(itMuros=paredes.begin();itMuros!=paredes.end();itMuros++){
        if((*itMuros)->collidesWithItem(objeto)) return true;
    }
    return false;
}

void MainWindow::actualizar()
{
    // Lógica para los enemigos tipo  (enemigo1)
    enemigo1 * punteroEnemigos1; //para poder usar los metodos de los elementos de la lista
    timerProyectilEnemigo++; // Incrementa el contador del temporizador.

    for(itEnemigos1=goku.begin(); itEnemigos1!=goku.end();){
        punteroEnemigos1=*itEnemigos1;

        if(EvaluarColision(punteroEnemigos1)==true)
            punteroEnemigos1->velocidad*=-1; // Invierte la dirección si choca con un muro.

        punteroEnemigos1->move(); // Mueve al enemigo.

        if(timerProyectilEnemigo == 9 || timerProyectilEnemigo == 19 || timerProyectilEnemigo == 29 || timerProyectilEnemigo == 39) { // Dispara en varios intervalos para que no sea solo uno
            balasEnemigo1.push_back(new proyectil(punteroEnemigos1->posx,punteroEnemigos1->posy,
                                                  punteroEnemigos1->direccionDisp,5,4));
            mapaEscena->addItem(balasEnemigo1.back());
        }

        // Colisiones balas personaje con Enemigo1--------------------------------------------------
        for(it=balasPersonaje.begin();it!=balasPersonaje.end();){
            if(punteroEnemigos1->collidesWithItem(*it)){
                punteroEnemigos1->vida-=10;
                mapaEscena->removeItem(*it);
                delete *it;
                it = balasPersonaje.erase(it);
                continue;
            }
            ++it;
        }

        if(punteroEnemigos1->vida<=0){
            mapaEscena->removeItem(punteroEnemigos1);
            delete punteroEnemigos1;
            itEnemigos1 = goku.erase(itEnemigos1);
            continue;
        }
        ++itEnemigos1;
    }

    // Reiniciar el timer de disparo global si es necesario
    if(timerProyectilEnemigo >= 40){
        timerProyectilEnemigo = 0;
    }

    // Colisiones de las balas de Enemigo1 (balasEnemigo1) con el jugador y los muros.
    for (it = balasEnemigo1.begin(); it != balasEnemigo1.end(); )
    {
        bool balaEliminada = false;
        // Colisión de la bala con el jugador
        if (tulio->collidesWithItem(*it)) {
            tulio->setVida(tulio->getVida() - 10);
            ui->vidaT->setNum(tulio->getVida()); // Actualizar la UI

            mapaEscena->removeItem(*it);
            delete *it;
            it = balasEnemigo1.erase(it);
            balaEliminada = true;
        }
        // Colisión de la bala con los muros
        else if (EvaluarColision(*it)) {
            mapaEscena->removeItem(*it);
            delete *it;
            it = balasEnemigo1.erase(it);
            balaEliminada = true;
        }

        // Si la bala no fue eliminada, avanzamos al siguiente elemento.
        if (!balaEliminada) {
            ++it;
        }
    }

    // Colisiones balas de personaje con los muros (ya estaba, pero aseguro el borrado seguro)
    for(it=balasPersonaje.begin(); it!=balasPersonaje.end();){
        if(EvaluarColision(*it)==true){
            try {
                mapaEscena->removeItem(*it);
                delete *it;
                it = balasPersonaje.erase(it);
                continue;
            }  catch (char c) {
                // Manejo de excepción, aunque el borrado seguro debería reducir la necesidad.
            }
        }
        ++it;
    }
}


void MainWindow::on_Nueva_clicked()
{
    ui->USER->show();
    ui->L_usuario->show();
    ui->Cargar->hide();
    ui->Nueva->hide();
    ui->REGISTER->show();
    ui->Salir->hide();
    ui->multi->hide();
}
void MainWindow::on_REGISTER_clicked()
{
    ui->USER->show();
    User=ui->USER->text();
    setUser(User);
    cuenta=new sesion(User,"100","15","0");
    if(cuenta->busquedaUsuario()==true){
        ui->reintentar->show();
        ui->ocupado->show();
        User=ui->USER->text();
        cuenta=new sesion(User,"100","15","0");
        setUser(User);
    }
    else{

        guardar.open("textos/usuarios.txt",ios::app);
        try {
            if(!guardar.is_open())
                throw '1';
        }  catch (char c) {
            if(c=='1')
                cout<<"No ha leido el archivo"<<endl;
        }

        guardar << cuenta->usuario.toStdString() << ","
                << cuenta->vida.toStdString() << ","
                << cuenta->municion.toStdString() << "," // <--- Corregido
                << cuenta->mapa.toStdString() << endl;   // <--- Corregido
        guardar.close();
        ui->USER->hide();
        ui->REGISTER->hide();
        ui->reintentar->hide();
        ui->ocupado->hide();
        ui->REGISTER->hide();
        ui->L_usuario->hide();
        setUser(User);
        ui->graphicsView->show();
        ui->graphicsView->centerOn(tulio);
        ui->multi->hide();
        ui->vidaT->show();
    }
}


void MainWindow::on_Cargar_clicked()
{
    ui->USER->show();
    ui->L_usuario->show();
    ui->Cargar->hide();
    ui->Nueva->hide();
    ui->Salir->hide();
    ui->Start->show();
    ui->multi->hide();
}
void MainWindow::on_Start_clicked()
{
    ui->USER->show();
    User=ui->USER->text();
    cuenta=new sesion(User,"0","0","0");
    if(cuenta->busquedaUsuario()==false){
        ui->reintentar_2->show();
        ui->ocupado_2->show();
        User=ui->USER->text();
        cuenta=new sesion(User,"0","0","0");
        setUser(User);
    }
    else{

        leer.open("textos/usuarios.txt",ios::in);
        try {
            if(!leer.is_open())
                throw '1';
        }  catch (char c) {
            if(c=='1')
                cout<<"No ha leido el archivo"<<endl;
        }
        string linea;
        while(getline(leer, linea)){
            string pedazoLinea;
            short int valores[4];
            int tramo=0;
            tramo=linea.find(',');
            if(User==linea.substr(0,tramo).c_str() ){
                for(int i=0;i<4;i++){
                    if(i<3){
                        tramo=linea.find(',');
                        pedazoLinea=linea.substr(0,tramo);
                        valores[i]=atoi(pedazoLinea.c_str());
                        linea=linea.substr(tramo+1);
                    }
                    else
                        valores[i]=atoi(linea.c_str());
                }
                tulio->setVida(valores[1]);
                tulio->setMunicion(valores[2]);
                tulio->setMapa(valores[3]);
                //ui->BarraVida->setValue(tulio->getVida());
                cout<<tulio->mapa;
                if(tulio->mapa==1){
                    tulio->setPos(900,70);
                    tulio->posx=900;
                    tulio->posy=70; //450,17  550,445
                    cargarNivel2();
                }
                if(tulio->mapa==2){
                    tulio->setPos(20,660);
                    tulio->posx=20;
                    tulio->posy=660;
                    cargarNivel3();
                    trampa1->timer->stop();
                }
            }
        }
        setUser(User);
        leer.close();
        ui->USER->hide();
        ui->REGISTER->hide();
        ui->reintentar_2->hide();
        ui->ocupado_2->hide();
        ui->L_usuario->hide();
        ui->Start->hide();
        ui->graphicsView->show();
        ui->graphicsView->setScene(mapaEscena);
        mapaEscena->setSceneRect(0,0,960,960);
        ui->graphicsView->centerOn(tulio);
        ui->multi->hide();
        ui->vidaT->show();
    }
}


void MainWindow::on_Salir_clicked()
{
    QApplication::quit();
}

void MainWindow::on_multi_clicked()
{
    ui->Cargar->hide();
    ui->Nueva->hide();
    ui->Salir->hide();
    ui->multi->hide();
    ui->graphicsView->setScene(multiplayer);
    multiplayer->setSceneRect(0,0,500,500);
    multiplayer->setBackgroundBrush(QBrush(QImage(":/mapa/imagenes/arena.png")));
    ui->graphicsView->show();
    iniciaMulti=true;
    timer1->stop();
    jugador1=new personaje(40,20,30);
    jugador1->velocidad+=15;
    multiplayer->addItem(jugador1);
    jugador2=new personaje(50,20,30);
    jugador2->velocidad+=15;
    multiplayer->addItem(jugador2);
    timerMultiPlayer->start(100);
}

void MainWindow::colisionMultiplayer()
{
    for(itbalasJugador1=balasJugador1.begin();itbalasJugador1!=balasJugador1.end();
         ){
        if(jugador2->collidesWithItem(*itbalasJugador1)){
            multiplayer->removeItem(*itbalasJugador1);
            delete *itbalasJugador1;
            itbalasJugador1 = balasJugador1.erase(itbalasJugador1);
            jugador2->vida-=5;
            continue;
        }
        ++itbalasJugador1;
    }
    for(itbalasJugador2=balasJugador2.begin();itbalasJugador2!=balasJugador2.end();
         ){
        if(jugador1->collidesWithItem(*itbalasJugador2)){
            multiplayer->removeItem(*itbalasJugador2);
            delete *itbalasJugador2;
            itbalasJugador2 = balasJugador2.erase(itbalasJugador2);
            jugador1->vida-=5;
            continue;
        }
        ++itbalasJugador2;
    }
    if(jugador1->vida<=0){
        QApplication::quit();
    }
    else if(jugador2->vida<=0){
        QApplication::quit();
    }
}
