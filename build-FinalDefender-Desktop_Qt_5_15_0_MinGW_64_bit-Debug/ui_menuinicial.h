/********************************************************************************
** Form generated from reading UI file 'menuinicial.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUINICIAL_H
#define UI_MENUINICIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuInicial
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Solitario;
    QPushButton *Multijugador;
    QPushButton *CargarPartida;
    QPushButton *Instrucciones;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *nombre;
    QLineEdit *contrasena;
    QPushButton *Continuar;
    QPushButton *atras;
    QLabel *label_3;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuInicial)
    {
        if (MenuInicial->objectName().isEmpty())
            MenuInicial->setObjectName(QString::fromUtf8("MenuInicial"));
        MenuInicial->resize(800, 800);
        MenuInicial->setMinimumSize(QSize(800, 800));
        MenuInicial->setMaximumSize(QSize(800, 800));
        MenuInicial->setAutoFillBackground(false);
        MenuInicial->setStyleSheet(QString::fromUtf8("background-color: rgb(61, 0, 153);"));
        centralwidget = new QWidget(MenuInicial);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 200, 500, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Solitario = new QPushButton(verticalLayoutWidget);
        Solitario->setObjectName(QString::fromUtf8("Solitario"));
        Solitario->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Fixedsys\";"));

        verticalLayout_2->addWidget(Solitario);

        Multijugador = new QPushButton(verticalLayoutWidget);
        Multijugador->setObjectName(QString::fromUtf8("Multijugador"));
        Multijugador->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Fixedsys\";"));

        verticalLayout_2->addWidget(Multijugador);

        CargarPartida = new QPushButton(verticalLayoutWidget);
        CargarPartida->setObjectName(QString::fromUtf8("CargarPartida"));
        CargarPartida->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Fixedsys\";"));

        verticalLayout_2->addWidget(CargarPartida);

        Instrucciones = new QPushButton(verticalLayoutWidget);
        Instrucciones->setObjectName(QString::fromUtf8("Instrucciones"));
        Instrucciones->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Fixedsys\";"));

        verticalLayout_2->addWidget(Instrucciones);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(280, 390, 212, 108));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        nombre = new QLineEdit(verticalLayoutWidget_2);
        nombre->setObjectName(QString::fromUtf8("nombre"));
        nombre->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Fixedsys\";\n"
"background-color: rgba(103, 52, 213, 100);"));
        nombre->setMaxLength(20);
        nombre->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(nombre);

        contrasena = new QLineEdit(verticalLayoutWidget_2);
        contrasena->setObjectName(QString::fromUtf8("contrasena"));
        contrasena->setStyleSheet(QString::fromUtf8("font: 700 9pt \"Fixedsys\";\n"
"background-color: rgba(103, 52, 213, 100);"));
        contrasena->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(contrasena);

        Continuar = new QPushButton(centralwidget);
        Continuar->setObjectName(QString::fromUtf8("Continuar"));
        Continuar->setGeometry(QRect(280, 520, 101, 28));
        Continuar->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Fixedsys\";"));
        atras = new QPushButton(centralwidget);
        atras->setObjectName(QString::fromUtf8("atras"));
        atras->setGeometry(QRect(400, 520, 93, 28));
        atras->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 700 12pt \"Fixedsys\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 80, 631, 91));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"border-bottom-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(100, 154, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"font: 700 48pt \"Sitka Text\";"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 800, 800));
        graphicsView->setMinimumSize(QSize(800, 800));
        graphicsView->setMaximumSize(QSize(800, 800));
        MenuInicial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MenuInicial);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MenuInicial->setMenuBar(menubar);
        statusbar = new QStatusBar(MenuInicial);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MenuInicial->setStatusBar(statusbar);

        retranslateUi(MenuInicial);

        QMetaObject::connectSlotsByName(MenuInicial);
    } // setupUi

    void retranslateUi(QMainWindow *MenuInicial)
    {
        MenuInicial->setWindowTitle(QCoreApplication::translate("MenuInicial", "MainWindow", nullptr));
        Solitario->setText(QCoreApplication::translate("MenuInicial", "UN SOLO JUGADOR", nullptr));
        Multijugador->setText(QCoreApplication::translate("MenuInicial", "DOS JUGADORES", nullptr));
        CargarPartida->setText(QCoreApplication::translate("MenuInicial", "CARGAR PARTIDA", nullptr));
        Instrucciones->setText(QCoreApplication::translate("MenuInicial", "INSTRUCCIONES", nullptr));
        nombre->setText(QCoreApplication::translate("MenuInicial", "NOMBRE", nullptr));
        contrasena->setText(QCoreApplication::translate("MenuInicial", "CONTRASE\303\221A", nullptr));
        Continuar->setText(QCoreApplication::translate("MenuInicial", "CONTINUAR", nullptr));
        atras->setText(QCoreApplication::translate("MenuInicial", "VOLVER", nullptr));
        label_3->setText(QCoreApplication::translate("MenuInicial", "FINAL DEFENDER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuInicial: public Ui_MenuInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUINICIAL_H
