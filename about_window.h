#ifndef ABOUT_WINDOW_H
#define ABOUT_WINDOW_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>

namespace Ui
{
    class about_window;
}

class about_window: public QDialog
{
private:
    Ui::about_window *ui;
    Q_OBJECT

private slots:
    void on_pushButton_clicked();
    void on_paypalButton_clicked();

public:
    explicit about_window (QWidget *parent = 0);
    ~about_window();
};

#endif
