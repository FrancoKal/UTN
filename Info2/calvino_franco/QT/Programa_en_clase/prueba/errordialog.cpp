#include "errordialog.h"
#include "ui_errordialog.h"
/*#include "mainwindow.h"
#include "ui_mainwindow.h"*/

errorDialog::errorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorDialog)
{
    ui->setupUi(this);
    //connect(Ui::MainWindow().boton_ok, SIGNAL(/*Ui::MainWindow().boton_ok->*/clicked()), this, SLOT(mostrar()));
}

errorDialog::~errorDialog()
{
    delete ui;
}
