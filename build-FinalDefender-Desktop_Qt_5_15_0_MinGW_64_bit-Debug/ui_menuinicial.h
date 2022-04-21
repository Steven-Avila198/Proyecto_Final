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
    QLabel *label;
    QLineEdit *nombre;
    QLabel *label_2;
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
        MenuInicial->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        centralwidget = new QWidget(MenuInicial);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(80, 200, 271, 171));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Solitario = new QPushButton(verticalLayoutWidget);
        Solitario->setObjectName(QString::fromUtf8("Solitario"));
        Solitario->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));

        verticalLayout_2->addWidget(Solitario);

        Multijugador = new QPushButton(verticalLayoutWidget);
        Multijugador->setObjectName(QString::fromUtf8("Multijugador"));
        Multijugador->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));

        verticalLayout_2->addWidget(Multijugador);

        CargarPartida = new QPushButton(verticalLayoutWidget);
        CargarPartida->setObjectName(QString::fromUtf8("CargarPartida"));
        CargarPartida->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));

        verticalLayout_2->addWidget(CargarPartida);

        Instrucciones = new QPushButton(verticalLayoutWidget);
        Instrucciones->setObjectName(QString::fromUtf8("Instrucciones"));
        Instrucciones->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));

        verticalLayout_2->addWidget(Instrucciones);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(360, 200, 212, 107));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));

        verticalLayout_3->addWidget(label);

        nombre = new QLineEdit(verticalLayoutWidget_2);
        nombre->setObjectName(QString::fromUtf8("nombre"));

        verticalLayout_3->addWidget(nombre);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));

        verticalLayout_3->addWidget(label_2);

        contrasena = new QLineEdit(verticalLayoutWidget_2);
        contrasena->setObjectName(QString::fromUtf8("contrasena"));

        verticalLayout_3->addWidget(contrasena);

        Continuar = new QPushButton(centralwidget);
        Continuar->setObjectName(QString::fromUtf8("Continuar"));
        Continuar->setGeometry(QRect(330, 440, 101, 28));
        Continuar->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));
        atras = new QPushButton(centralwidget);
        atras->setObjectName(QString::fromUtf8("atras"));
        atras->setGeometry(QRect(620, 440, 93, 28));
        atras->setStyleSheet(QString::fromUtf8("font: 75 12pt \"8514oem\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 90, 631, 91));
        label_3->setStyleSheet(QString::fromUtf8("font: 48pt \"Bauhaus 93\";"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 600, 600));
        graphicsView->setMinimumSize(QSize(600, 600));
        graphicsView->setMaximumSize(QSize(600, 600));
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
        Solitario->setText(QCoreApplication::translate("MenuInicial", "SOLITARIO", nullptr));
        Multijugador->setText(QCoreApplication::translate("MenuInicial", "MULTIJUGADOR", nullptr));
        CargarPartida->setText(QCoreApplication::translate("MenuInicial", "CARGAR PARTIDA", nullptr));
        Instrucciones->setText(QCoreApplication::translate("MenuInicial", "INSTRUCCIONES", nullptr));
#if QT_CONFIG(whatsthis)
        label->setWhatsThis(QCoreApplication::translate("MenuInicial", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("MenuInicial", "       NOMBRE", nullptr));
        label_2->setText(QCoreApplication::translate("MenuInicial", "     CONTRASENA", nullptr));
        Continuar->setText(QCoreApplication::translate("MenuInicial", "CONTINUAR", nullptr));
        atras->setText(QCoreApplication::translate("MenuInicial", "VOLVER", nullptr));
        label_3->setText(QCoreApplication::translate("MenuInicial", "Final Defender", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuInicial: public Ui_MenuInicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUINICIAL_H
