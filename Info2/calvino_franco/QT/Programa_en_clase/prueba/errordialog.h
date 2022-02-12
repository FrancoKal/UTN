#ifndef ERRORDIALOG_H
#define ERRORDIALOG_H

#include <QDialog>

namespace Ui {
class errorDialog;
}

class errorDialog : public QDialog
{
    Q_OBJECT

    public:
        explicit errorDialog(QWidget *parent = nullptr);
        void mostrar () { show(); }
        ~errorDialog();

    private:
        Ui::errorDialog *ui;
};

#endif // ERRORDIALOG_H
