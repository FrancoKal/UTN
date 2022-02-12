#include "mainwindow.h"
#include "ui_mainwindow.h"

void writeLineEdit (QString s, QLineEdit* LE);
double Fahrenheit_a_Celcius (double F) { return (F - 32.0) * 5.0 / 9.0; }
double Celcius_a_Fahrenheit (double C) { return C * 9.0 / 5.0 + 32.0; }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->frame_fahrenheit->setDisabled(true);
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->lcdNumber_celcius, SLOT(display(int))); //Para que al cambiar el spinbox se muestre el numero en el LCD
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(realizarConversion_a_fahrenheit(int))); //Para que al cambiar el spinbox se realize la conversion en el lineEDit_fahrenheit
    connect(ui->lineEdit_celcius, SIGNAL(textChanged(QString)), this, SLOT(realizarConversion_a_fahrenheit(QString)));
    connect(ui->dial, SIGNAL(valueChanged(int)), ui->lcdNumber_fahrenheit, SLOT(display(int))); //Para que al girar el dial se muestre el numero en el LCD
    connect(ui->dial, SIGNAL(valueChanged(int)), this, SLOT(realizarConversion_a_celcius(int))); //Para que al girar el dial se realize la conversion en el lineEDit_fahrenheit
    connect(ui->lineEdit_fahrenheit, SIGNAL(textChanged(QString)), this, SLOT(realizarConversion_a_celcius(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

double realizarConversion (const QString& ingreso,  double convertir (double), bool *ok)
{
    bool LaConversionFueExitosa = true;
    double T = ingreso.toDouble(&LaConversionFueExitosa);
    double conversion = 0;

    if (LaConversionFueExitosa && convertir != NULL)
        conversion = convertir(T);

    *ok = LaConversionFueExitosa;

    return conversion;
}

void MainWindow::on_pushButton_emit_clicked()
{
    double T;
    bool LaConversionFueExitosa = true;
    QLineEdit *writeLE = NULL;
    QString LEinput;
    double (*convertir) (double) = NULL;

    if (ui->frame_celcius->isEnabled())
    {
         //realizarConversion_a_fahrenheit(ui->lineEdit_celcius->text());
        LEinput = ui->lineEdit_celcius->text();
        writeLE = ui->lineEdit_fahrenheit;
        convertir = Celcius_a_Fahrenheit;
    }
    else if (ui->frame_fahrenheit->isEnabled())
    {
        //realizarConversion_a_celcius(ui->lineEdit_fahrenheit->text());
        LEinput = ui->lineEdit_fahrenheit->text();
        writeLE = ui->lineEdit_celcius;
        convertir = Fahrenheit_a_Celcius;
    }

    if (!LEinput.isEmpty())
    {
        T = realizarConversion(LEinput, convertir, &LaConversionFueExitosa);

        if (LaConversionFueExitosa)
            writeLineEdit(QString::number(T), writeLE);
        else showErrorMessage("Error de conversion. Por favor revise su ingreso");
    }
}

void writeLineEdit (QString s, QLineEdit* LE)
{
    if (LE != NULL && !s.isEmpty())
        LE->setText(s);
}

void MainWindow::escribir_en_celcius (QString s)
{
    writeLineEdit(s, ui->lineEdit_celcius);
}

void MainWindow::escribir_en_fahrenheit (QString s)
{
    writeLineEdit(s, ui->lineEdit_fahrenheit);
}

void showErrorMessage (const char *message)
{
    QString m(message);
    QMessageBox e;

    e.setText(m);
    e.exec();
}

void MainWindow::realizarConversion_a_fahrenheit (int T)
{
    escribir_en_fahrenheit(QString::number(Celcius_a_Fahrenheit((double) T)));
}

void MainWindow::realizarConversion_a_fahrenheit (QString s)
{
    bool LaConversionFueExitosa = true;
    double conversion = realizarConversion(s, Celcius_a_Fahrenheit, &LaConversionFueExitosa);

    if (LaConversionFueExitosa)
        escribir_en_fahrenheit(QString::number(conversion));
}

void MainWindow::realizarConversion_a_celcius (int T)
{
    escribir_en_celcius(QString::number(Fahrenheit_a_Celcius((double) T)));
}

void MainWindow::realizarConversion_a_celcius (QString s)
{
    bool LaConversionFueExitosa = true;
    double conversion = realizarConversion(s, Fahrenheit_a_Celcius, &LaConversionFueExitosa);

    if (LaConversionFueExitosa)
        escribir_en_celcius(QString::number(conversion));
}

