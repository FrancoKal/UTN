#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        double Fahrenheit_a_Celcius (double F) { return (F - 32.0) * 5.0 / 9.0;}
        double Kelvin_a_Celcius (double K) { return K - 273.15; }
        double Celcius_a_Kelvin (double C) { return C + 273.15; }
        double Celcius_a_Fahrenheit (double C) { return C * 9.0 / 5.0 + 32.0;}
        void on_boton_ok_clicked();

        //void on_comboBox_tempDeIngreso_activated(const QString &arg1);
        void showErrorMessage (const char *message);

private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
