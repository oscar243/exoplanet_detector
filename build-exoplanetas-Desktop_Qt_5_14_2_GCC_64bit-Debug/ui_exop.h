/********************************************************************************
** Form generated from reading UI file 'exop.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXOP_H
#define UI_EXOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_exop
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_encont_valores;
    QPushButton *pushButton_guardar_arch;
    QPushButton *pushButton_cargar_db;
    QLineEdit *lineEdit_min1;
    QLabel *label_min1;
    QListWidget *listWidget_t_brillo;
    QLineEdit *lineEdit_min2;
    QLabel *label_min2;
    QLineEdit *lineEdit_tmin2;
    QLineEdit *lineEdit_tmin1;
    QLineEdit *lineEdit_max;
    QLabel *label_max;
    QLabel *label_periodo;
    QLineEdit *lineEdit_periodo;
    QLineEdit *lineEdit_radp;
    QLabel *label_radio;
    QCustomPlot *grafica_datos;
    QLabel *label_tmin1;
    QLabel *label_tmin2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *exop)
    {
        if (exop->objectName().isEmpty())
            exop->setObjectName(QString::fromUtf8("exop"));
        exop->resize(800, 600);
        centralwidget = new QWidget(exop);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_encont_valores = new QPushButton(centralwidget);
        pushButton_encont_valores->setObjectName(QString::fromUtf8("pushButton_encont_valores"));
        pushButton_encont_valores->setGeometry(QRect(270, 30, 141, 23));
        pushButton_guardar_arch = new QPushButton(centralwidget);
        pushButton_guardar_arch->setObjectName(QString::fromUtf8("pushButton_guardar_arch"));
        pushButton_guardar_arch->setGeometry(QRect(460, 30, 151, 23));
        pushButton_cargar_db = new QPushButton(centralwidget);
        pushButton_cargar_db->setObjectName(QString::fromUtf8("pushButton_cargar_db"));
        pushButton_cargar_db->setGeometry(QRect(30, 30, 191, 23));
        lineEdit_min1 = new QLineEdit(centralwidget);
        lineEdit_min1->setObjectName(QString::fromUtf8("lineEdit_min1"));
        lineEdit_min1->setGeometry(QRect(200, 90, 121, 23));
        label_min1 = new QLabel(centralwidget);
        label_min1->setObjectName(QString::fromUtf8("label_min1"));
        label_min1->setGeometry(QRect(70, 90, 101, 16));
        listWidget_t_brillo = new QListWidget(centralwidget);
        listWidget_t_brillo->setObjectName(QString::fromUtf8("listWidget_t_brillo"));
        listWidget_t_brillo->setGeometry(QRect(30, 280, 241, 261));
        lineEdit_min2 = new QLineEdit(centralwidget);
        lineEdit_min2->setObjectName(QString::fromUtf8("lineEdit_min2"));
        lineEdit_min2->setGeometry(QRect(200, 130, 121, 23));
        label_min2 = new QLabel(centralwidget);
        label_min2->setObjectName(QString::fromUtf8("label_min2"));
        label_min2->setGeometry(QRect(70, 130, 101, 16));
        lineEdit_tmin2 = new QLineEdit(centralwidget);
        lineEdit_tmin2->setObjectName(QString::fromUtf8("lineEdit_tmin2"));
        lineEdit_tmin2->setGeometry(QRect(610, 130, 121, 23));
        lineEdit_tmin1 = new QLineEdit(centralwidget);
        lineEdit_tmin1->setObjectName(QString::fromUtf8("lineEdit_tmin1"));
        lineEdit_tmin1->setGeometry(QRect(610, 90, 121, 23));
        lineEdit_max = new QLineEdit(centralwidget);
        lineEdit_max->setObjectName(QString::fromUtf8("lineEdit_max"));
        lineEdit_max->setGeometry(QRect(200, 170, 121, 23));
        label_max = new QLabel(centralwidget);
        label_max->setObjectName(QString::fromUtf8("label_max"));
        label_max->setGeometry(QRect(70, 170, 51, 16));
        label_periodo = new QLabel(centralwidget);
        label_periodo->setObjectName(QString::fromUtf8("label_periodo"));
        label_periodo->setGeometry(QRect(30, 220, 161, 20));
        lineEdit_periodo = new QLineEdit(centralwidget);
        lineEdit_periodo->setObjectName(QString::fromUtf8("lineEdit_periodo"));
        lineEdit_periodo->setGeometry(QRect(200, 220, 121, 23));
        lineEdit_radp = new QLineEdit(centralwidget);
        lineEdit_radp->setObjectName(QString::fromUtf8("lineEdit_radp"));
        lineEdit_radp->setGeometry(QRect(610, 220, 121, 23));
        label_radio = new QLabel(centralwidget);
        label_radio->setObjectName(QString::fromUtf8("label_radio"));
        label_radio->setGeometry(QRect(390, 220, 211, 20));
        grafica_datos = new QCustomPlot(centralwidget);
        grafica_datos->setObjectName(QString::fromUtf8("grafica_datos"));
        grafica_datos->setGeometry(QRect(300, 280, 461, 261));
        label_tmin1 = new QLabel(centralwidget);
        label_tmin1->setObjectName(QString::fromUtf8("label_tmin1"));
        label_tmin1->setGeometry(QRect(420, 90, 181, 16));
        label_tmin2 = new QLabel(centralwidget);
        label_tmin2->setObjectName(QString::fromUtf8("label_tmin2"));
        label_tmin2->setGeometry(QRect(420, 130, 181, 16));
        exop->setCentralWidget(centralwidget);
        menubar = new QMenuBar(exop);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        exop->setMenuBar(menubar);
        statusbar = new QStatusBar(exop);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        exop->setStatusBar(statusbar);

        retranslateUi(exop);

        QMetaObject::connectSlotsByName(exop);
    } // setupUi

    void retranslateUi(QMainWindow *exop)
    {
        exop->setWindowTitle(QCoreApplication::translate("exop", "exop", nullptr));
        pushButton_encont_valores->setText(QCoreApplication::translate("exop", "Encontrar valores", nullptr));
        pushButton_guardar_arch->setText(QCoreApplication::translate("exop", "Guardar en archivo", nullptr));
        pushButton_cargar_db->setText(QCoreApplication::translate("exop", "Cargar la base de datos", nullptr));
        label_min1->setText(QCoreApplication::translate("exop", "Primer m\303\255nimo", nullptr));
        label_min2->setText(QCoreApplication::translate("exop", "Segundo m\303\255nimo", nullptr));
        label_max->setText(QCoreApplication::translate("exop", "Maximo", nullptr));
        label_periodo->setText(QCoreApplication::translate("exop", "Periodo orbital [Dias]", nullptr));
        label_radio->setText(QCoreApplication::translate("exop", "Radio del planeta [Jupiters]", nullptr));
        label_tmin1->setText(QCoreApplication::translate("exop", "Tiempo del primer m\303\255nimo", nullptr));
        label_tmin2->setText(QCoreApplication::translate("exop", "Tiempo del segundo m\303\255nimo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exop: public Ui_exop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXOP_H
