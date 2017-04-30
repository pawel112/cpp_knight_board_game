#include "tile.h"
#include "main_window.h"

extern main_window *m_window;

void tile::mousePressEvent (QMouseEvent *event)
{
    Q_UNUSED(event)
    m_window->set_clicked_field (true);
    m_window->validate (this, ++m_window->clicked_fields);
}

void tile::display (char elem)
{
    this->set_piece_name (elem);

    if (this->get_piece_color() && this->get_piece())
    {
        this->setPixmap (QPixmap (":/images/pawn_white.svg"));
    }
    else if (this->get_piece())
    {
        this->setPixmap (QPixmap (":/images/pawn_black.svg"));
    }
    else
    {
        this->clear();
    }
}

void tile::tile_display()
{
    if (this->get_tile_color())
    {
        this->setStyleSheet ("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    }
    else
    {
        this->setStyleSheet ("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
    }
}
