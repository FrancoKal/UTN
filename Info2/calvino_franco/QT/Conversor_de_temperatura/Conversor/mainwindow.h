#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

        void escribir_en_celcius (QString s);
        void escribir_en_fahrenheit (QString s);

    private slots:
        void on_pushButton_emit_clicked();
        void realizarConversion_a_fahrenheit (int T);
        void realizarConversion_a_celcius (int T);
        void realizarConversion_a_fahrenheit (QString s);
        void realizarConversion_a_celcius (QString s);

    private:
        Ui::MainWindow *ui;
};

void showErrorMessage (const char *message);
double realizarConversion (const QString& ingreso,  double convertir (double), bool *ok = nullptr);


#endif // MAINWINDOW_H
