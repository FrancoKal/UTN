#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>

namespace Ui { class errorDialog; }

class errorDialog : public QDialog
{
    public:
        errorDialog (QWidget *parent = 0);
        ~errorDialog() { delete ui; }
        show() {}

    private:
        Ui::errorDialog *ui;
};

#endif // ERRORWINDOW_H
