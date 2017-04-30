#include "rules_window.h"
#include "ui_rules_window.h"
#include "language.h"

rules_window::rules_window(QWidget *parent):
    QDialog(parent),
    ui(new Ui::rules_window)
    {
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ui->setupUi(this);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle(QString::fromStdString(language::get_game_rules_name()));
        ui->textBrowser->setText(QString::fromStdString(language::get_game_rules_text()));
        ui->pushButton->setText(QString::fromStdString(language::get_close_text()));
    }

rules_window::~rules_window()
{
    delete ui;
}

void rules_window::on_pushButton_clicked()
{
    this->close();
}
