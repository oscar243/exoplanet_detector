#ifndef EXOP_H
#define EXOP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class exop; }
QT_END_NAMESPACE

class exop : public QMainWindow
{
    Q_OBJECT

public:
    exop(QWidget *parent = nullptr);
    ~exop();

private slots:
    void on_pushButton_cargar_db_clicked();

    void on_pushButton_encont_valores_clicked();

    void on_pushButton_guardar_arch_clicked();

private:
    Ui::exop *ui;
};
#endif // EXOP_H
