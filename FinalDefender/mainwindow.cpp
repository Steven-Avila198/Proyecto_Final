#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    menu = new MenuInicial();


    jugador[0] = new QGraphicsScene;
    jugador[1] = new QGraphicsScene;
    Final = new QGraphicsScene;

    ////agregar sprite ////
    Final->setBackgroundBrush(QImage("../"));
    jugador[0]->setBackgroundBrush(QImage("../"));
    jugador[1]->setBackgroundBrush(QImage("../"));
    ////////////////////////

    for(int i = 0; i < 3; i++){
        Niveles.at(i) = new QGraphicsScene;
    }
    for(int i = 0; i < 2; i++){
        naves.at(i) = new personaje(1);
    }
    for(int i = 0; i < 4; i++){
        Escenas.at(i) = new QGraphicsScene;
    }
    astronauta = new personaje();
    level1 = new QGraphicsRectItem();
    laser = new Laser();
    boss = new Boss();
    BasuraEspacial = new basura();
    for(int i = 0; i < 2; i++){
        shots[i] = new disparo();
    }


    //Nivel 1 //
////////////////////////////////////////////////////////////////////////////////////////////////////
    level1 = Niveles.at(0)->addRect(0,0,80,80, QPen(QColor(1,1,1)), QImage(":/Sprites Personajes/Galaxia.jpg"));
    Niveles.at(0)->addItem(astronauta);
    Niveles.at(0)->addItem(BasuraEspacial);
    BasuraEspacial->posx = 400;
    BasuraEspacial->setPos(400,-25);
    astronauta->setPos(400,400);
    astronauta->pos_x = 400;
    astronauta->pos_y = 400;
    Niveles.at(0)->setBackgroundBrush(QImage(":/Sprites Personajes/Galaxia.jpg"));



////////////////////////////////////////////////////////////////////////////////////////////////////

    //Nivel 2//

////////////////////////////////////////////////////////////////////////////////////////////////////

    Niveles.at(1)->addItem(naves.at(0));
    Niveles.at(1)->addItem(shots[0]);
    shots[0]->setPos(-30,-30);
    Niveles.at(1)->setBackgroundBrush(QImage(":/Sprites Personajes/Galaxia.jpg"));
    naves.at(0)->setPos(55,400);
    naves.at(0)->pos_x = 55;
    naves.at(0)->pos_y = 400;

    for(int g = 0; g < 55; g++){
        grados[g] = 0;
    }
    for(int v = 0; v < 10; v++){
        velocidad[v] = 85*qSin(qDegreesToRadians(30.0));
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////

    Niveles.at(2)->addItem(boss);
    Niveles.at(2)->addItem(naves.at(1));
    Niveles.at(2)->addItem(laser);
    Niveles.at(2)->addItem(shots[1]);
    shots[1]->setPos(-30,-30);
    laser->setPos(0,-150);
    Niveles.at(2)->setBackgroundBrush(QImage(":/Sprites Personajes/Galaxia.jpg"));
    naves.at(1)->setPos(55,400);
    naves.at(1)->pos_x = 55;
    naves.at(1)->pos_y = 400;
    boss->setPos(650,400);
    boss->posx = 650;
    boss->posy = 400;

    for(int g = 0; g < 7; g++){
        grados_boss[g] = 0;
    }

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(conector()));
    timer->start(1);

}

void MainWindow::Level1()
{
    int ran_x, ran_y;
    ran_x = QRandomGenerator::global()->bounded(710);
    ran_y = QRandomGenerator::global()->bounded(710);
    level1->setPos(ran_x,ran_y);
}

void MainWindow::MovBasura()
{
    BasuraEspacial->setPos(BasuraEspacial->posx, BasuraEspacial->posy+=13);
}

void MainWindow::Level2(int a = 0)
{
    if(a == 0){
        indexm++;
        //se agrega los meteoritos y se usa addEllipse
        meteoritos.at(indexm) = Niveles.at(1)->addEllipse(720,QRandomGenerator::global()->bounded(710),90,90, QPen(QColor(1,1,1)), QImage(":/Sprites Personajes/asteroide.jpg"));

        pruebam++;
    }
    else{
        indexc++;
        //se agrega los cometas y se usa addellipse
        //falta sprite de cometa
        cometas.at(indexc) = Niveles.at(1)->addEllipse(720,naves.at(0)->pos_y,45,45, QPen(QColor(1,1,1)), QImage("../"));

        pruebac++;
    }

}

void MainWindow::MovMeteoritos()
{
    //Movimiento de los meteoritos y colisiones
    for(int i = 0; i < pruebam; i++){
        if(meteoritos.at(i) != NULL){
            meteoritos.at(i)->setPos(meteoritos.at(i)->pos().x()-0.3,70*qSin(qDegreesToRadians(grados[i]))-(meteoritos.at(i)->pos().y()));
            grados[i]++;
            if(meteoritos.at(i)->pos().x() < -810){
                Niveles.at(1)->removeItem(meteoritos.at(i));
                naves.at(0)->puntos+=100;
                meteoritos.at(i) = NULL;
            }
            if(naves.at(0)->collidesWithItem(meteoritos.at(i))){
                Niveles.at(1)->removeItem(meteoritos.at(i));
                meteoritos.at(i) = NULL;
                naves.at(0)->vidas--;
                if(naves.at(0)->vidas == 0 and turno == 0){
                    reiniciar = 0;
                }
                if(naves.at(0)->vidas == 0 and turno == 3){
                    if(progreso == 0){
                        reiniciar = 0;
                        fin = 1;
                        GameOverMulti();
                    }
                }
                ui->lcdNumber->display(naves.at(0)->vidas);
            }
        }
    }
}

void MainWindow::MovCometas()
{
    //movimiento de los cometas y colisiones
    static float t = 0.01, Vx = 100*qCos(qDegreesToRadians(30.0)), g = 9.81;
    for(int i = 0; i < pruebac; i++){
        if(cometas.at(i) != NULL){
            cometas.at(i)->setPos(cometas.at(i)->pos().x()-(Vx*t), cometas.at(i)->pos().y()-(velocidad[i])*t+((g/2)*(t*t)));//posicion del objeto
            velocidad[i] = velocidad[i] - g*t;
            if(cometas.at(i)->pos().x() < -765){
                naves.at(0)->puntos+=100;
                Niveles.at(1)->removeItem(cometas.at(i));
                cometas.at(i) = NULL;
            }
            if(naves.at(0)->collidesWithItem(cometas.at(i))){ //colision con el personaje
                Niveles.at(1)->removeItem(cometas.at(i));
                cometas.at(i) = NULL;
                naves.at(0)->vidas--;
                if(naves.at(0)->vidas == 0 and turno == 0){
                    reiniciar = 0;
                }
                if(naves.at(0)->vidas == 0 and turno == 3){
                    if(progreso == 0){
                        reiniciar = 0;
                        fin = 1;
                        GameOverMulti();
                    }
                }
                ui->lcdNumber->display(naves.at(0)->vidas);
            }
        }
    }
}

void MainWindow::MovMiniBoss()
{
    //el mini boss tiene movimiento circular al rededor de Boss
    for(int i = 0; i < orbita; i++){
        mini.at(i)->setPos( -200*qCos(qDegreesToRadians(grados_boss[i]))+623, 200*qSin(qDegreesToRadians(grados_boss[i]))+373);
        grados_boss[i]++;
    }

}

void MainWindow::MovBoss()
{

    if(y == 653){
        direccion = 1;
    }
    if(y == 163){
        direccion = 0;
    }
    if(direccion == 0){
        y+=10;
    }
    else{
        y-=10;
    }
    for(int i = 0; i < orbita; i++){
        if(mini.at(i) != NULL){
            mini.at(i)->setPos( -200*qCos(qDegreesToRadians(grados_boss[i]))+623, 200*qSin(qDegreesToRadians(grados_boss[i]))+y);
            grados_boss[i]++;
        }
    }
    boss->setPos(boss->posx,y);
    boss->posy = y;
}

void MainWindow::MovDisparo()
{
        shots[nivel-2]->posx+=10;
        shots[nivel-2]->setPos(shots[nivel-2]->posx, shots[nivel-2]->posy);

}

void MainWindow::DanoBoss()
{
    if(shots[nivel-2]->posx >= 755){
        shots[nivel-2]->setPos(-30,-30);
        shots[nivel-2]->posx = -30;
        cont_disparos = 0;
    }
    if(orbita == 7){
        for(int i = 0; i < orbita; i++){
            if(mini.at(i) != NULL){
                if(shots[1]->collidesWithItem(mini.at(i))){
                    shots[1]->setPos(-30,-30);
                    shots[1]->posx = -30;
                    naves.at(1)->puntos+=100;
                    Niveles.at(2)->removeItem(mini.at(i));
                    mini.at(i) = NULL;
                    cont_disparos = 0;
                }
            }
        }
    }
    if(defensa < 7){
        if(mini.at(defensa) == NULL){
            defensa++;
        }
    }
    if(shots[1]->collidesWithItem(boss)){
        shots[1]->setPos(-30,-30);
        shots[1]->posx = -30;
        cont_disparos = 0;
        if(defensa == 7){
            naves.at(0)->puntos+=500;
            boss->vidas--;

        }
    }
    if(turno == 1 and boss->vidas == 0){
        progreso = 1;
        turno = 2;
        seconds = 0;
    }
    if(turno == 3 and boss->vidas == 0){
        progreso++;
        if(progreso == 2){
            nivel = 4;
        }
        else{
            reiniciar = 0;
            fin = 1;
            GameOverMulti();
        }
    }
    if(turno ==  0 and boss->vidas == 0){
        nivel = 4;
    }
    for(int i = 0; i < pruebam; i++){
        if(meteoritos.at(i) != NULL){
            if(shots[nivel-2]->collidesWithItem(meteoritos.at(i))){
                Niveles.at(1)->removeItem(meteoritos.at(i));
                meteoritos.at(i) = NULL;
                shots[nivel-2]->setPos(-30,-30);
                shots[nivel-2]->posx = -30;
                cont_disparos = 0;
            }
        }
    }
}

void MainWindow::MovLaser()
{
    laser->setPos(boss->posx-410, boss->posy);
    if(DuracionLaser == 4000){
        laser->columnas = 0;
    }
    if(DuracionLaser == 7500){
        DuracionLaser = 0;
        DanoLaser = 0;
        laser->setPos(0, -150);
    }


}

void MainWindow::CambioEscena()
{
    if(nivel == 1){
        ui->graphicsView->setScene(Niveles.at(0));
    }
    if(nivel == 2){
        ui->graphicsView->setScene(Niveles.at(1));
    }
    if(nivel == 3){
        ui->graphicsView->setScene(Niveles.at(2));
    }
    ui->graphicsView->setSceneRect(400,400,10,10);
    ui->graphicsView->show();

}

void MainWindow::limpiarEscena2()
{
    for(int i = 0; i < pruebac; i++){
        if(cometas.at(i) != NULL){
            Niveles.at(1)->removeItem(cometas.at(i));
            cometas.at(i) = NULL;
        }
    }
    for(int i = 0; i < pruebam; i++){
        if(meteoritos.at(i) != NULL){
            Niveles.at(1)->removeItem(meteoritos.at(i));
            meteoritos.at(i) = NULL;
        }
    }
}

void MainWindow::limpiarEscena3()
{
    for(int i = 0; i < orbita; i++){
        if(mini.at(i) != NULL){
            Niveles.at(2)->removeItem(mini.at(i));
            mini.at(i) = NULL;
        }
    }
}

void MainWindow::GameOver()
{
    if(astronauta->vidas == 0){
        if(reiniciar == 0){
            Escenas.at(3)->setBackgroundBrush(QImage(":/Sprites Personajes/game over.png"));
            ui->graphicsView->setScene(Escenas.at(3));
            ui->graphicsView->show();
        }
        else{
            level1->setPos(0,0);
            astronauta->setPos(400,400);
            astronauta->pos_x = 400;
            astronauta->pos_y = 400;
            BasuraEspacial->setPos(400,-25);
            BasuraEspacial->posx = 400;
            BasuraEspacial->posy = -25;
            seconds = 11500;
            nivel = 0;
            cambio = 0;
            astronauta->puntos = 0;
            astronauta->vidas = 3;
        }
    }
    if(naves.at(0)->vidas == 0){
        if(reiniciar == 0){
            Escenas.at(3)->setBackgroundBrush(QImage(":/Sprites Personajes/game over.png"));
            ui->graphicsView->setScene(Escenas.at(3));
            ui->graphicsView->show();
        }
        else{
            limpiarEscena2();
            shots[nivel-2]->setPos(-30,-30);
            naves.at(0)->setPos(55,400);
            naves.at(0)->pos_x = 55;
            naves.at(0)->pos_y = 400;

            for(int g = 0; g < 55; g++){
                grados[g] = 0;
            }
            for(int v = 0; v < 10; v++){
                velocidad[v] = 85*qSin(qDegreesToRadians(30.0));
            }
            indexm = -1, indexc = -1;
            pruebam = 0, pruebac = 0;
            nivel = 1;
            naves.at(0)->vidas = 3;
            naves.at(0)->puntos = 0;
        }
    }
    if(naves.at(1)->vidas == 0){
        if(reiniciar == 0){
            Escenas.at(3)->setBackgroundBrush(QImage(":/Sprites Personajes/game over.png"));
            ui->graphicsView->setScene(Escenas.at(3));
            ui->graphicsView->show();
        }
        else{
            limpiarEscena3();
            laser->setPos(0,-150);
            shots[nivel-2]->setPos(-30,-30);
            naves.at(1)->setPos(55,400);
            naves.at(1)->pos_x = 55;
            naves.at(1)->pos_y = 400;
            boss->setPos(650,400);
            boss->posx = 650;
            boss->posy = 400;
            y = 373;
            boss->vidas = 3;

            for(int g = 0; g < 7; g++){
                grados_boss[g] = 0;
            }

            naves.at(1)->vidas = 3;
            naves.at(1)->puntos = 0;
            cont_disparos = 0;
            orbita = 0;
            index = 0;
            seconds = 60500;
            defensa = 0;
            DuracionLaser = 0;
            nivel = 2;
        }
    }
}

void MainWindow::PasarTurno()
{
    if(nivel == 1 and turno == 2){
        ui->graphicsView->setScene(jugador[turno-1]);
        ui->graphicsView->show();
        level1->setPos(0,0);
        astronauta->setPos(400,400);
        astronauta->pos_x = 400;
        astronauta->pos_y = 400;
        BasuraEspacial->setPos(400,-25);
        BasuraEspacial->posx = 400;
        BasuraEspacial->posy = -25;
        astronauta->puntos = 0;
        astronauta->vidas = 3;
    }
    if(nivel == 2 and turno == 2){
        ui->graphicsView->setScene(jugador[turno-1]);
        ui->graphicsView->show();
        limpiarEscena2();
        shots[nivel-2]->setPos(-30,-30);
        naves.at(0)->setPos(55,400);
        naves.at(0)->pos_x = 55;
        naves.at(0)->pos_y = 400;

        for(int g = 0; g < 55; g++){
            grados[g] = 0;
        }
        for(int v = 0; v < 10; v++){
            velocidad[v] = 85*qSin(qDegreesToRadians(30.0));
        }
        indexm = -1, indexc = -1;
        pruebam = 0, pruebac = 0;
        nivel = 2;
        naves.at(0)->vidas = 3;
        naves.at(0)->puntos = 0;
    }
    if(nivel == 3 and turno == 2){
        ui->graphicsView->setScene(jugador[turno-1]);
        ui->graphicsView->show();
        limpiarEscena3();
        laser->setPos(0,-150);
        shots[nivel-2]->setPos(-30,-30);
        naves.at(1)->setPos(55,400);
        naves.at(1)->pos_x = 55;
        naves.at(1)->pos_y = 400;
        boss->setPos(650,400);
        boss->posx = 650;
        boss->posy = 400;
        y = 373;
        boss->vidas = 3;

        for(int g = 0; g < 7; g++){
            grados_boss[g] = 0;
        }

        naves.at(1)->vidas = 3;
        naves.at(1)->puntos = 0;
        cont_disparos = 0;
        orbita = 0;
        index = 0;
        defensa = 0;
        DuracionLaser = 0;
        nivel = 3;
    }
}

void MainWindow::GameOverMulti()
{
    if(fin == 1 and progreso == 0 and nivel == 1){
        if(reiniciar == 0){
            Escenas.at(3)->setBackgroundBrush(QImage(":/Sprites Personajes/game over.png"));
            ui->graphicsView->setScene(Escenas.at(3));
            ui->graphicsView->show();
        }
        else{
            level1->setPos(0,0);
            astronauta->setPos(400,400);
            astronauta->pos_x = 400;
            astronauta->pos_y = 400;
            BasuraEspacial->setPos(400,-25);
            BasuraEspacial->posx = 400;
            BasuraEspacial->posy = -25;
            seconds = 11500;
            nivel = 0;
            cambio = 0;
            turno = 1;
            continuar = 0;
            astronauta->puntos = 0;
            astronauta->vidas = 3;
        }
    }
    if(fin == 1 and progreso == 0 and nivel == 2){
        if(reiniciar == 0){
            Escenas.at(3)->setBackgroundBrush(QImage(":/Sprites Personajes/game over.png"));
            ui->graphicsView->setScene(Escenas.at(3));
            ui->graphicsView->show();
        }
        else{
            limpiarEscena2();
            shots[nivel-2]->setPos(-30,-30);
            naves.at(0)->setPos(55,400);
            naves.at(0)->pos_x = 55;
            naves.at(0)->pos_y = 400;

            for(int g = 0; g < 55; g++){
                grados[g] = 0;
            }
            for(int v = 0; v < 10; v++){
                velocidad[v] = 85*qSin(qDegreesToRadians(30.0));
            }
            indexm = -1, indexc = -1;
            pruebam = 0, pruebac = 0;
            nivel = 1;
            cambio = 0;
            turno = 3;
            progreso = 1;
            astronauta->puntos = 2000;
            continuar = 0;
            naves.at(0)->vidas = 3;
            naves.at(0)->puntos = 0;
        }
    }
    if(fin == 1 and progreso <= 1 and nivel == 3){
        if(reiniciar == 0){
            Escenas.at(3)->setBackgroundBrush(QImage(":/Sprites Personajes/game over.png"));
            ui->graphicsView->setScene(Escenas.at(3));
            ui->graphicsView->show();
        }
        else{
            limpiarEscena3();
            laser->setPos(0,-150);
            shots[nivel-2]->setPos(-30,-30);
            naves.at(1)->setPos(55,400);
            naves.at(1)->pos_x = 55;
            naves.at(1)->pos_y = 400;
            boss->setPos(650,400);
            boss->posx = 650;
            boss->posy = 400;
            y = 373;
            boss->vidas = 3;

            for(int g = 0; g < 7; g++){
                grados_boss[g] = 0;
            }

            naves.at(1)->vidas = 3;
            naves.at(1)->puntos = 0;
            cont_disparos = 0;
            orbita = 0;
            index = 0;
            seconds = 60500;
            cambio = 0;
            continuar = 0;
            turno = 3;
            progreso = 1;
            defensa = 0;
            DuracionLaser = 0;
            nivel = 2;
        }
    }

}


void MainWindow::conector()
{
    if(curso == 0){
        menu->show();
        this->hide();
        if(menu->cerrar != 0){
            nombre = menu->name;
            contrasena = menu->pasword;
            if(menu->multi == 1){
                turno = 1;
            }
            nivel = menu->nivel;
            if(nivel == 1){
                seconds = 11500;
                nivel = 0;
            }
            if(nivel == 2){
                nivel = 1;
                astronauta->puntos = 2000;
                if(turno != 0){
                    turno = 3;
                    progreso++;
                }
            }
            if(nivel == 3){
                nivel = 2;
                seconds = 60500;
                if(turno != 0){
                    turno = 3;
                    progreso++;
                }
            }
            menu->~MenuInicial();
            this->show();
            curso = 1;
        }
    }
    else if (curso == 1){
        curso = 2;
        if(nivel == 0 and seconds == 0){
            input = new intro();
            Escenas.at(0)->addItem(input);
            input->setPos(400,400);
            ui->graphicsView->setScene(Escenas.at(0));
            ui->graphicsView->setSceneRect(400,400,10,10);
            ui->graphicsView->show();
        }
    }
    else{
        seconds++;
        if(turno == 0){
            GameOver();
        }
        else{
            GameOverMulti();
        }
        if(seconds >= 11500 and nivel == 0){
            fin = 0;
          //agregar titulo del nivel  Escenas.at(1)->setBackgroundBrush(QImage("../"));
            ui->graphicsView->setScene(Escenas.at(1));
            ui->graphicsView->show();
        }
        if(reiniciar != 0){
            CambioEscena();
        }
        if(nivel == 1){
            ui->lcdNumber_2->display(astronauta->puntos);
            ui->lcdNumber->display(astronauta->vidas);
            if(turno == 1 and continuar == 0){
                if(seconds%1000 == 0){
                    continuar = 1;
                    seconds = 0;
                }
                ui->graphicsView->setScene(jugador[turno-1]);
                ui->graphicsView->show();
            }
            else if(turno == 2){
                PasarTurno();
                if(seconds%1000 == 0){
                    turno = 3;
                }
            }
            else{
                if(astronauta->vidas == 0 and turno == 3 and progreso >= 1){
                    cambio = 0;
                   //agregar titulo del nivel Escenas.at(2)->setBackgroundBrush(QImage("../"));
                    ui->graphicsView->setScene(Escenas.at(2));
                    ui->graphicsView->show();
                }

                if(seconds%50 == 0 and astronauta->puntos > 100 and astronauta->puntos < 2000 and astronauta->vidas > 0){
                    MovBasura();
                }
                if(BasuraEspacial->posy >= 780){
                    BasuraEspacial->setPos(astronauta->pos_x, -25);
                    BasuraEspacial->posx = astronauta->pos_x;
                    BasuraEspacial->posy = -25;
                }
                if(astronauta->collidesWithItem(BasuraEspacial)){
                    astronauta->vidas--;
                    ui->lcdNumber->display(astronauta->vidas);
                    BasuraEspacial->posx = -780;
                    BasuraEspacial->setPos(BasuraEspacial->posx, BasuraEspacial->posy);
                    if(astronauta->vidas == 0 and turno == 0){
                        reiniciar = 0;
                    }
                    if(turno == 1 and astronauta->vidas == 0){
                        turno = 2;
                        seconds = 0;
                    }
                    if(turno == 3 and astronauta->vidas == 0){
                        if(progreso == 0){
                            reiniciar = 0;
                            fin = 1;
                        }
                    }
                }
                if(seconds%3500 == 0 or astronauta->collidesWithItem(level1)){
                    Level1();
                    if(seconds%3500 == 0){
                        astronauta->vidas--;
                        ui->lcdNumber->display(astronauta->vidas);
                        if(astronauta->vidas == 0 and turno == 0){
                            reiniciar = 0;
                        }
                        if(turno == 1 and astronauta->vidas == 0){
                            turno = 2;
                            seconds = 0;
                        }
                        if(turno == 3 and astronauta->vidas == 0){
                            if(progreso == 0){
                                reiniciar = 0;
                                fin = 1;
                            }
                        }
                        ui->lcdNumber->display(astronauta->vidas);
                    }
                    else{
                        astronauta->puntos+=100;
                        ui->lcdNumber_2->display(astronauta->puntos);
                    }
                    seconds = 0;
                }
                if(astronauta->puntos == 2000 and turno == 0){
                    cambio = 0;
                 //falta sprite   Escenas.at(2)->setBackgroundBrush(QImage("../"));
                    ui->graphicsView->setScene(Escenas.at(2));
                    ui->graphicsView->show();

                }
                if(astronauta->puntos == 2000){
                    if(turno == 1){
                        turno = 2;
                        progreso++;
                        seconds = 0;
                    }
                    if(turno == 3){
                        progreso++;
                        if(progreso >= 1){
                            cambio = 0;
                         //falta sprite   Escenas.at(2)->setBackgroundBrush(QImage("../"));
                            ui->graphicsView->setScene(Escenas.at(2));
                            ui->graphicsView->show();
                        }
                    }
                }
            }
        }
        else if(nivel == 2){
            if(naves.at(0)->vidas == 0 and turno == 3){
                if(progreso == 0){
                    reiniciar = 0;
                    fin = 1;
                    GameOverMulti();
                }
            }
            if(seconds >= 60500 or naves.at(0)->vidas == 0){
                if(turno == 3){
                    if(progreso == 1)
                        progreso++;
                    if(progreso >= 1){
                        nave_index = 1;
                        cambio = 0;
                    //falta sprite    Escenas.at(3)->setBackgroundBrush(QImage("../"));
                        ui->graphicsView->setScene(Escenas.at(3));
                        ui->graphicsView->show();
                    }
                }
            }
            if(turno == 1 and continuar == 0){
                if(seconds%1000 == 0){
                    continuar = 1;
                    seconds = 0;
                }
                ui->graphicsView->setScene(jugador[turno-1]);
                ui->graphicsView->show();
            }
            else if(turno == 2){
                PasarTurno();
                if(seconds%1000 == 0){
                    turno = 3;
                }
            }
            else{
                if(turno == 1 and naves.at(0)->vidas == 0){
                    turno = 2;
                    seconds = 0;
                }
                if(seconds >= 60500){
                    if(turno == 1){
                        turno = 2;
                        progreso++;
                        seconds = 0;
                    }
                }
                if(cont_disparos > 0 and shots[nivel-2]->posx != -30){
                    DanoBoss();
                    if(seconds%30 == 0)
                        MovDisparo();
                }
                if(seconds >= 60500 and turno == 0){
                    nave_index = 1;
                    cambio = 0;
                //falta sprite    Escenas.at(3)->setBackgroundBrush(QImage("../"));
                    ui->graphicsView->setScene(Escenas.at(3));
                    ui->graphicsView->show();
                }
                ui->lcdNumber->display(naves.at(0)->vidas);
                ui->lcdNumber_2->display(naves.at(0)->puntos);
                if(pruebam > 0 and seconds%2 == 0 and fin != 1)
                    MovMeteoritos();
                if(pruebac > 0 and seconds%3 == 0 and fin != 1)
                    MovCometas();
                if(seconds%1000 == 0 and indexm < 54){
                    Level2();
                    if(seconds%6000 == 0 and indexc < 9){
                        Level2(1);
                    }
                }
            }
        }
        else if(nivel == 3){
            nave_index = 1;
            if(turno == 1 and continuar == 0){
                if(seconds%1000 == 0){
                    continuar = 1;
                    seconds = 0;
                }
                ui->graphicsView->setScene(jugador[turno-1]);
                ui->graphicsView->show();
            }
            else if(turno == 2 and seconds != 0){
                PasarTurno();
                if(seconds%1000 == 0){
                    turno = 3;
                }
            }
            else{
                ui->lcdNumber->display(naves.at(1)->vidas);
                ui->lcdNumber_2->display(naves.at(1)->puntos);
                if(cont_disparos > 0 and shots[nivel-2]->posx != -30){
                    DanoBoss();
                    if(seconds%30 == 0)
                        MovDisparo();
                }
                if(orbita < 7){
                    if(seconds%500 == 0){
                        mini.at(index) = new miniboss();
                        mini.at(index)->setPos(650,400);
                        Niveles.at(2)->addItem(mini.at(index));
                        index++;
                        orbita++;
                    }
                    if(orbita > 0 and seconds%10 == 0){
                        MovMiniBoss();
                    }
                }
                else{
                    DuracionLaser++;
                    if(DuracionLaser >= 4000){
                        MovLaser();
                        if(naves.at(1)->collidesWithItem(laser) and DanoLaser == 0){
                            naves.at(1)->vidas--;
                            ui->lcdNumber->display(naves.at(1)->vidas);
                            if(naves.at(1)->vidas == 0 and turno == 0){
                                reiniciar = 0;
                            }
                            if(turno == 1 and naves.at(1)->vidas == 0){
                                turno = 2;
                                seconds = 0;
                            }
                            if(turno == 3 and naves.at(1)->vidas == 0){
                                if(progreso <= 1){
                                    reiniciar = 0;
                                    fin = 1;
                                    GameOverMulti();
                                }
                                else{
                                    nivel = 4;
                                }
                            }
                            DanoLaser = 1;
                        }
                    }
                    if(orbita > 0 and seconds%70 == 0 and boss != NULL){
                        MovBoss();
                    }
                    if(naves.at(1)->collidesWithItem(boss)){
                        naves.at(1)->vidas--;
                        ui->lcdNumber->display(naves.at(1)->vidas);
                        if(naves.at(1)->vidas == 0 and turno == 0){
                            reiniciar = 0;
                        }
                        if(turno == 1 and naves.at(1)->vidas == 0){
                            turno = 2;
                            seconds = 0;
                        }
                        if(turno == 3 and naves.at(1)->vidas == 0){
                            if(progreso <= 1){
                                reiniciar = 0;
                                fin = 1;
                                GameOverMulti();
                            }
                            else{
                                nivel = 4;
                            }
                        }
                        naves.at(1)->setPos(55,400);
                        naves.at(1)->pos_x = 55;
                        naves.at(1)->pos_y = 400;
                    }
                    for(int i = 0; i < orbita; i++){
                        if(mini.at(i) != NULL){
                            if(naves.at(1)->collidesWithItem(mini.at(i))){
                                naves.at(1)->vidas--;
                                ui->lcdNumber->display(naves.at(1)->vidas);
                                if(naves.at(1)->vidas == 0 and turno == 0){
                                    reiniciar = 0;
                                }
                                if(turno == 1 and naves.at(1)->vidas == 0){
                                    turno = 2;
                                    seconds = 0;
                                }
                                if(turno == 3 and naves.at(1)->vidas == 0){
                                    if(progreso <= 1){
                                        reiniciar = 0;
                                        fin = 1;
                                        GameOverMulti();
                                    }
                                    else{
                                        nivel = 4;
                                    }
                                }
                                naves.at(1)->setPos(55,400);
                                naves.at(1)->pos_x = 55;
                                naves.at(1)->pos_y = 400;
                            }
                        }
                    }
                }
            }

        }
        else if(nivel == 4){
            ui->graphicsView->setScene(Final);
            ui->graphicsView->show();
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::Escritura()
{
    string prueba;

    Lectura(prueba);

    ofstream archivo;

    archivo.open("../FinalDefender/BaseDatos.txt");
    if(!archivo.is_open()){
        cout << "El archivo " << "BaseDatos.txt" << " no pudo ser abierto" << endl;
        exit(1);
    }

    archivo << prueba;
    archivo.close();
}

void MainWindow::Lectura(string &texto)
{
    string add;
    string prueba;
    int actual = 0, coma = 0;

    ifstream archivo;

    archivo.open("../FinalDefender/BaseDatos.txt");

    if(!archivo.is_open()){
        cout << "El archivo " << "BaseDatos.txt" << " no pudo ser abierto" << endl;
        exit(1);
    }
    while(getline(archivo, add)){
        for(int i = 0; i < int(add.size()); i++){
            if(add.at(i) == ',' and actual < 2){
                texto += prueba+',';
            }
            if(add.at(i) != ','){
                prueba += add.at(i);
            }
            else{
                coma++;
                if(coma == 4){
                    coma = 0;
                    texto += '\n';
                }
                if(prueba == nombre){
                    actual = 1;
                }
                if(prueba == contrasena and actual == 1){
                    actual = 2;
                }
                if(actual == 2 and coma == 3){
                    actual = 0;
                    if(nivel == 1){
                        texto+="1,";
                    }
                    if(nivel == 2){
                        texto+="2,";
                    }
                    if(nivel == 3){
                        texto+="3,";
                    }
                }
                prueba = "";
            }
        }
    }
    archivo.close();
}*/

void MainWindow::keyPressEvent(QKeyEvent *e)
{
        switch (e->key()) {
        case Qt::Key_A:
            astronauta->setPos(astronauta->pos_x-=15, astronauta->pos_y);
            if(astronauta->pos_x <= 50){
                astronauta->setPos(astronauta->pos_x+=15, astronauta->pos_y);
            }
            astronauta->direccion(1);
            if(nivel == 2 or nivel == 3){
                naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x-=15, naves.at(nave_index)->pos_y);
                if(naves.at(nave_index)->pos_x <= 50){
                    naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x+=15, naves.at(nave_index)->pos_y);
                }
            }
            break;
        case Qt::Key_S:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=15);
            if(astronauta->pos_y >= 750){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=15);
            }
            if(nivel == 2 or nivel == 3){
                naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x, naves.at(nave_index)->pos_y+=15);
                if(naves.at(nave_index)->pos_y >= 750){
                    naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x, naves.at(nave_index)->pos_y-=15);
                }
            }
            break;
        case Qt::Key_D:
            astronauta->setPos(astronauta->pos_x+=15, astronauta->pos_y);
            if(astronauta->pos_x >= 750){
                astronauta->setPos(astronauta->pos_x-=15, astronauta->pos_y);
            }
            if(nivel == 2 or nivel == 3){
                naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x+=15, naves.at(nave_index)->pos_y);
                if(naves.at(nave_index)->pos_x >= 750){
                    naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x-=15, naves.at(nave_index)->pos_y);
                }
            }
            astronauta->direccion(0);
            break;
        case Qt::Key_W:
            astronauta->setPos(astronauta->pos_x, astronauta->pos_y-=15);
            if(astronauta->pos_y <= 50){
                astronauta->setPos(astronauta->pos_x, astronauta->pos_y+=15);
            }
            if(nivel == 2 or nivel == 3){
                naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x, naves.at(nave_index)->pos_y-=15);
                if(naves.at(nave_index)->pos_y <= 50){
                    naves.at(nave_index)->setPos(naves.at(nave_index)->pos_x, naves.at(nave_index)->pos_y+=15);
                }
            }
            break;
        case Qt::Key_Space:
            if(nivel >= 2){
                cont_disparos++;
                if(cont_disparos == 1){
                    shots[nivel-2]->posx = naves.at(nave_index)->pos_x+70;
                    shots[nivel-2]->posy = naves.at(nave_index)->pos_y;
                    shots[nivel-2]->setPos(shots[nivel-2]->posx,shots[nivel-2]->posy);
                }
            }
            break;
        case Qt::Key_Return:
            if(cambio == 0){
                nivel++;
               // Escritura();
                cambio++;
                seconds = 0;
                if(turno == 3){
                    turno = 1;
                    continuar = 0;
                    fin = 0;
                    progreso = 0;
                }
            }
            break;
        case Qt::Key_X:
            if(reiniciar == 0){
                reiniciar = 1;
                cambio = 0;
            }
            break;
        case Qt::Key_T:
            if(nivel == 4){
                exit(1);
            }
            break;
        default:
            break;
        }
}
