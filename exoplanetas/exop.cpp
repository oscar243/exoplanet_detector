#include "exop.h"
#include "ui_exop.h"

#include <QSqlDatabase>         //lectura de base de datos
#include <QSqlQuery>            //lectura de base de datos
#include <math.h>               //para sacar la raiz para el calculo del radio
#include <QFile>                // para documentar
#include <QString>              // para documentar
#include <QTextStream>          // para documentar

#define TAM_MAX 500 //El número máximo de datos que se guardaran
//guardar cada columna en cada vector para facilidad en las funciones
double d_time[TAM_MAX]; //En este vector van los tiempos extraídos de la base de datos
double d_brightness[TAM_MAX]; //En este los valores de la luminosidad normalizados

unsigned int cantidad_datos = 0; //Se guarda el número de columnas obtenidas de la DB

bool datos_cargados=0;    //banderas para que haga lo mismo varias veces
bool datos_calculados=0;    //para saber si ya se ha hecho algo

exop::exop(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::exop)
{
    ui->setupUi(this);


    ui->listWidget_t_brillo ->addItem("Tiempo[dias]   Luminosidad");     //encabezados
                                                                        //de la lista
    ui->listWidget_t_brillo->addItem("");
}

exop::~exop()
{
    delete ui;
}


double maximo(double v[], int n)    //sacar maximo
{
    double max;

    for (int i = 0; i < n; i++)
        if (i == 0 || max < v[i])
            max = v[i];


    return max;
}

double minimo(double v[], int n)    // sacar el minimo
{
    double min;

    for (int i = 0; i < n; i++)
        if (i == 0 || min > v[i])
            min = v[i];

    return min;
}

void dos_minimos(double v[], int n, double &min_1, double &min_2, int &pos1, int &pos2)
{
    double minimo1=0;
    double minimo2=0;
    int posicion_min_1=0;
    int posicion_min_2=0;

    double valor_ref = (maximo(v,n) +minimo(v,n))/2;

    int i=0;
    bool bandera =0;

    while (i < n)
    {
        if (v[i]<valor_ref)
        {
           if(v[i]-v[i+1]<0 && posicion_min_1==0)
           {
               minimo1=v[i];
               posicion_min_1=i;
               while (i > n || v[i]>valor_ref) {i++;}
               bandera = 1;
           }

           if(v[i]-v[i+1]<0 && posicion_min_2==0 && bandera == 0)
           {
               minimo2=v[i];
               posicion_min_2=i;
               i=n;
           }
        }
        else if (bandera == 1)
        {
            bandera = 0;
        }
        i++;
    }
    min_1=minimo1;
    min_2=minimo2;
    pos1=posicion_min_1;
    pos2=posicion_min_2;

}

void exop::on_pushButton_cargar_db_clicked()
{
    if(datos_cargados==0)
    {
        QString ruta_base_datos = "/home/alse/Documents/exop1/exoplanets_DB/grupo3_exop.db";
        QSqlDatabase base_datos = QSqlDatabase::addDatabase("QSQLITE");
        base_datos.setDatabaseName(ruta_base_datos);
        base_datos.open();
        QSqlQuery query2;
        QString linea;

        query2.exec("select * from exop3");

        while (query2.next())
        {
            linea=query2.value(0).toString()+"\t    "+query2.value(1).toString();
            // convertir cadena de caracteres
            ui->listWidget_t_brillo->addItem(linea);
            d_time[cantidad_datos]=query2.value(0).toDouble();  //guarda como double
            d_brightness[cantidad_datos]=query2.value(1).toDouble();

            cantidad_datos++;  // para saber la cantidad de datos
        }

        base_datos.close();

        datos_cargados=1;
    }

}

void exop::on_pushButton_encont_valores_clicked() //se activa solo si los datos estan cargados
{
    double max_brightness=0;
    double min_brightness=0;

    double min_brightness_1=0;
    double min_brightness_2=0;

    int pos_min_1 = 0;
    int pos_min_2 = 0;

    if(datos_cargados==1)
    {
        max_brightness= maximo(d_brightness,cantidad_datos);
        min_brightness= minimo(d_brightness,cantidad_datos);

        dos_minimos(d_brightness, cantidad_datos, min_brightness_1, min_brightness_2, pos_min_1, pos_min_2);

        ui->lineEdit_tmin1->setText(QString().setNum(d_time[pos_min_1], 'g', 10));
        ui->lineEdit_tmin2->setText(QString().setNum(d_time[pos_min_2], 'g', 10));
        ui->lineEdit_min1->setText(QString().setNum(min_brightness_1, 'g', 10));
        ui->lineEdit_min2->setText(QString().setNum(min_brightness_2, 'g', 10));

        ui->lineEdit_max->setText(QString().setNum(max_brightness, 'g', 10));

        ui->lineEdit_periodo->setText(QString().setNum(d_time[pos_min_2]-d_time[pos_min_1], 'g', 10));

        ui->lineEdit_radp->setText(QString().setNum(1.69*10*sqrt(max_brightness-min_brightness), 'g', 10));

        //Graficar los datos
        QVector<double> x(cantidad_datos), y(cantidad_datos);

        for (int j=0; j<cantidad_datos; ++j)
        {
            x[j]=d_time[j];
            y[j]=d_brightness[j];
        }

        ui->grafica_datos->addGraph();
        ui->grafica_datos->graph(0)->setData(x,y);
        ui->grafica_datos->xAxis->setLabel("Tiempo");
        ui->grafica_datos->yAxis->setLabel("Luminosidad");
        ui->grafica_datos->xAxis->setRange(d_time[0],d_time[cantidad_datos-1]);
        ui->grafica_datos->yAxis->setRange(min_brightness,max_brightness);
        ui->grafica_datos->replot();

        datos_calculados=1;
    }
}



void exop::on_pushButton_guardar_arch_clicked()
{
    if(datos_calculados)
    {
        QString file = "/home/alse/Documents/exop1/exoplanetas/datos_de_salida.txt";
        QFile outputFile(file);
        outputFile.open(QIODevice::WriteOnly);

        QString str;

        if(!outputFile.isOpen())
        {
            //Alerta por si no abria
        }

        QTextStream outStream(&outputFile);

        // muestra como saca los datos
        str="Máximo, " + ui->lineEdit_max->text()+"\n";
        str=str+"Mínimo1, " + ui->lineEdit_min1->text()+"\n";
        str=str+"Mínimo2, " + ui->lineEdit_min2->text()+"\n";
        str=str+"TiempoMínimo1, " + ui->lineEdit_tmin1->text()+"\n";
        str=str+"TiempoMínimo2, " + ui->lineEdit_tmin2->text()+"\n";
        str=str+"Periodo_orbital, " + ui->lineEdit_periodo->text()+"\n";
        str=str+"Radio_planeta, " + ui->lineEdit_radp->text();

        outStream << str;

        outputFile.close();
    }
}
