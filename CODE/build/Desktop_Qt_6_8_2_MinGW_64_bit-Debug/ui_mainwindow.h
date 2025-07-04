/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *Nueva;
    QPushButton *Cargar;
    QPushButton *Salir;
    QLabel *L_usuario;
    QLineEdit *USER;
    QPushButton *REGISTER;
    QLabel *ocupado;
    QLabel *reintentar;
    QPushButton *Start;
    QLabel *ocupado_2;
    QLabel *reintentar_2;
    QPushButton *multi;
    QLabel *vidaT;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 900);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/mapa/imagenes/fondo.png);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(-340, -20, 960, 960));
        Nueva = new QPushButton(centralwidget);
        Nueva->setObjectName("Nueva");
        Nueva->setGeometry(QRect(220, 180, 76, 23));
        Nueva->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Cargar = new QPushButton(centralwidget);
        Cargar->setObjectName("Cargar");
        Cargar->setGeometry(QRect(220, 220, 78, 23));
        Cargar->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        Salir = new QPushButton(centralwidget);
        Salir->setObjectName("Salir");
        Salir->setGeometry(QRect(220, 290, 75, 23));
        Salir->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        L_usuario = new QLabel(centralwidget);
        L_usuario->setObjectName("L_usuario");
        L_usuario->setGeometry(QRect(220, 200, 80, 19));
        L_usuario->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Unispace\";\n"
"color: rgb(255, 255, 255);"));
        USER = new QLineEdit(centralwidget);
        USER->setObjectName("USER");
        USER->setGeometry(QRect(300, 200, 108, 22));
        USER->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        REGISTER = new QPushButton(centralwidget);
        REGISTER->setObjectName("REGISTER");
        REGISTER->setGeometry(QRect(320, 220, 75, 23));
        REGISTER->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ocupado = new QLabel(centralwidget);
        ocupado->setObjectName("ocupado");
        ocupado->setGeometry(QRect(430, 200, 105, 14));
        ocupado->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";\n"
"color: rgb(170, 0, 0);"));
        reintentar = new QLabel(centralwidget);
        reintentar->setObjectName("reintentar");
        reintentar->setGeometry(QRect(300, 180, 147, 14));
        reintentar->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";\n"
"color: rgb(255, 255, 255);"));
        Start = new QPushButton(centralwidget);
        Start->setObjectName("Start");
        Start->setGeometry(QRect(320, 220, 75, 23));
        Start->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        ocupado_2 = new QLabel(centralwidget);
        ocupado_2->setObjectName("ocupado_2");
        ocupado_2->setGeometry(QRect(430, 200, 119, 14));
        ocupado_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";\n"
"color: rgb(170, 0, 0);"));
        reintentar_2 = new QLabel(centralwidget);
        reintentar_2->setObjectName("reintentar_2");
        reintentar_2->setGeometry(QRect(300, 180, 168, 14));
        reintentar_2->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Unispace\";\n"
"color: rgb(255, 255, 255);"));
        multi = new QPushButton(centralwidget);
        multi->setObjectName("multi");
        multi->setGeometry(QRect(220, 250, 75, 23));
        multi->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        vidaT = new QLabel(centralwidget);
        vidaT->setObjectName("vidaT");
        vidaT->setGeometry(QRect(30, 30, 91, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font.setPointSize(28);
        font.setBold(true);
        vidaT->setFont(font);
        vidaT->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 600, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        MainWindow->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        Nueva->setText(QCoreApplication::translate("MainWindow", "Nueva Partida", nullptr));
        Cargar->setText(QCoreApplication::translate("MainWindow", "Cargar Partida", nullptr));
        Salir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        L_usuario->setText(QCoreApplication::translate("MainWindow", "Usuario:", nullptr));
        REGISTER->setText(QCoreApplication::translate("MainWindow", "Registrar", nullptr));
        ocupado->setText(QCoreApplication::translate("MainWindow", "Usuario Ocupado", nullptr));
        reintentar->setText(QCoreApplication::translate("MainWindow", "Ingrese nuevo usuario", nullptr));
        Start->setText(QCoreApplication::translate("MainWindow", "Iniciar", nullptr));
        ocupado_2->setText(QCoreApplication::translate("MainWindow", "Usuario no existe", nullptr));
        reintentar_2->setText(QCoreApplication::translate("MainWindow", "Intente con otro usuario", nullptr));
        multi->setText(QCoreApplication::translate("MainWindow", "Multijugador", nullptr));
        vidaT->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
