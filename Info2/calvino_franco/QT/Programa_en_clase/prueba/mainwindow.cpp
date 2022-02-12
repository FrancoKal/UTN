#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

void ComboBox_insertItems (QComboBox *box, const char **items, int quantity);
void insertUnidades (QComboBox *box);

void ComboBox_insertItems (QComboBox *box, const char **items, int quantity)
{
    QStringList list;
    int i;

    for (i = 0; i < quantity; i++)
        list.append(items[i]);

    box->addItems(list);
}

void insertUnidades (QComboBox *box)
{
    const char *unidades[] = {"ºC", "K", "F"};

    ComboBox_insertItems(box, unidades, 3);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->resultado_temp->setReadOnly(true);
    insertUnidades(ui->comboBox_tempDeIngreso);
    insertUnidades(ui->comboBox_tempDeSalida);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_boton_ok_clicked()
{
    bool LaCoversionFueExitosa = true;
    double T_ingresada = ui->ingresar_temp->text().toDouble(&LaCoversionFueExitosa);
    double T_final = T_ingresada;
    QString resultado;

    if (LaCoversionFueExitosa)
    {
        if (ui->comboBox_tempDeIngreso->currentText() == "K")
            T_final = Kelvin_a_Celcius(T_ingresada);
        else if (ui->comboBox_tempDeIngreso->currentText() == "F")
            T_final = Fahrenheit_a_Celcius(T_ingresada);

        if (ui->comboBox_tempDeSalida->currentText() == "K")
            T_final = Celcius_a_Kelvin(T_final);
        else if (ui->comboBox_tempDeSalida->currentText() == "F")
            T_final = Celcius_a_Fahrenheit(T_final);

        resultado = QString::number(T_final);
        ui->resultado_temp->setText(resultado);
    }
    else showErrorMessage("Error de conversion. Por favor revise su ingreso");

}

void MainWindow::showErrorMessage (const char *message)
{
    QString m(message);
    QMessageBox e;

    e.setText(m);
    e.exec();
}
