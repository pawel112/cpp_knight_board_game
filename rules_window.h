#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QDialog>

namespace Ui
{
    class rules_window;
}

class rules_window: public QDialog
{
private:
    Q_OBJECT
    Ui::rules_window *ui;

private slots:
        void on_pushButton_clicked();

public:
    explicit rules_window (QWidget *parent = 0);
    ~rules_window();
};

#endif
