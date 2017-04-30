#ifndef CHOOSE_LANGUAGE_H
#define CHOOSE_LANGUAGE_H

#include <QDialog>

namespace Ui
{
    class choose_language;
}

class choose_language: public QDialog
{
private:
    Ui::choose_language *ui;
    Q_OBJECT

private slots:
    void on_en_button_clicked();
    void on_pl_button_clicked();

public:
    explicit choose_language (QWidget *parent = 0);
    ~choose_language();
};

#endif
