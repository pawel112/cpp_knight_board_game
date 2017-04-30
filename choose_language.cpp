#include "choose_language.h"
#include "ui_choose_language.h"
#include "main_window.h"
#include "language.h"

extern main_window *m_window;

choose_language::choose_language(QWidget *parent):
    QDialog(parent),
    ui(new Ui::choose_language)
    {
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ui->setupUi(this);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        this->setWindowTitle(QString::fromStdString(language::get_game_name()));
    }

choose_language::~choose_language()
{
    delete ui;
}

void choose_language::on_en_button_clicked()
{
    //choose English language
    language::set_en();
    m_window = new main_window();
    m_window->show();
    this->close();
}

void choose_language::on_pl_button_clicked()
{
    //choose Polish language
    language::set_pl();
    m_window = new main_window();
    m_window->show();
    this->close();
}
