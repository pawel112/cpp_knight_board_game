#include "about_window.h"
#include "ui_about_window.h"
#include "language.h"

about_window::about_window(QWidget *parent):
    QDialog(parent),
    ui(new Ui::about_window)
    {
        this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        ui->setupUi(this);
        this->setFixedHeight(this->height());
#ifdef __linux__        
        this->setFixedWidth(this->width()+25);
        ui->textBrowser->setFixedWidth(ui->textBrowser->width()+25);
#else
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
#endif
        this->setWindowTitle(QString::fromStdString(language::get_about_game_name()));
        ui->textBrowser->setText (QString::fromStdString(language::get_about_game_text()));
        ui->pushButton->setText(QString::fromStdString(language::get_close_text()));
        ui->paypalButton->setText(QString::fromStdString(language::get_donation_text()));
#ifdef __linux__
        ui->textBrowser->setFontWeight(5);
#endif
    }

about_window::~about_window()
{
    delete ui;
}

void about_window::on_pushButton_clicked()
{
    this->close();
}

void about_window::on_paypalButton_clicked()
{
    if (language::get_game_name() == "Gra Skoczek")
    {
        QDesktopServices::openUrl(QUrl("https://www.paypal.com/cgi-bin/webscr?cmd=_donations&business=paypal%40roszatycki%2epl&lc=US&item_name=Darowizna%20%2d%20gra%20Skoczek&no_note=0&currency_code=PLN&bn=PP%2dDonationsBF%3abtn_donate_LG%2egif%3aNonHostedGuest"));
    }
    else
    {
        QDesktopServices::openUrl(QUrl("https://www.paypal.com/us/cgi-bin/webscr?cmd=_flow&SESSION=wwGrgEJUdP4xgXXdEjhEoX5mgG_ToAyEtp1Ybe4-0XTiEGextXLl-ATPRqq&dispatch=5885d80a13c0db1f8e263663d3faee8d4fe1dd75ca3bd4f11d72275b28239088"));
    }
}
