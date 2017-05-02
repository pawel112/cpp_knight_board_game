#include "validation.h"
#include "settings.h"
#include "tile.h"
#include <iostream>

extern tile *main_tile[8][8];
extern main_window *m_window;

int validation::chooser (tile *temp)
{
    m_window->remove_blue();
    flag = validate_pawn (temp);
    orange();
    return flag;
}

int validation::validate_pawn (tile *temp)
{
    int row = 0;
    int col = 0;

    row = temp->get_row();
    col = temp->get_col();
    ret_val = 0;

    if (settings::get_game_started() == false)
    {
        return ret_val;
    }

    if (m_window->get_now_jumping() == true)
    {
        //jumps
        if (row+2 <= 7 && col+2 <= 7 && main_tile[row+1][col+1]->get_piece() && !main_tile[row+2][col+2]->get_piece() && temp->get_row() == m_window->get_jump_from_field(0) && temp->get_col() == m_window->get_jump_from_field(1))
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row+2][col+2]->get_tile_num());
            ret_val = 1;
        }

        if (row+2 <= 7 && col-2 >= 0 && main_tile[row+1][col-1]->get_piece() && !main_tile[row+2][col-2]->get_piece() && temp->get_row() == m_window->get_jump_from_field(0) && temp->get_col() == m_window->get_jump_from_field(1))
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row+2][col-2]->get_tile_num());
            ret_val = 1;
        }

        if (row-2 >= 0 && col-2 >= 0 && main_tile[row-1][col-1]->get_piece() && !main_tile[row-2][col-2]->get_piece() && temp->get_row() == m_window->get_jump_from_field(0) && temp->get_col() == m_window->get_jump_from_field(1))
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row-2][col-2]->get_tile_num());
            ret_val = 1;
        }

        if (row-2 >= 0 && col+2 <= 7 && main_tile[row-1][col+1]->get_piece() && !main_tile[row-2][col+2]->get_piece() && temp->get_row() == m_window->get_jump_from_field(0) && temp->get_col() == m_window->get_jump_from_field(1))
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row-2][col+2]->get_tile_num());
            ret_val = 1;
        }
    }
    else
    {
        if (row-1 >= 0 && col-1 >= 0 && !main_tile[row-1][col-1]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row-1][col-1]->get_tile_num());
            ret_val = 1;
        }

        if (row+1 <= 7 && col+1 <= 7 && !main_tile[row+1][col+1]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row+1][col+1]->get_tile_num());
            ret_val = 1;
        }

        if (row-1 >= 0 && col+1 <= 7 && !main_tile[row-1][col+1]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row-1][col+1]->get_tile_num());
            ret_val = 1;
        }

        if (row+1 <= 7 && col-1 >= 0 && !main_tile[row+1][col-1]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row+1][col-1]->get_tile_num());
            ret_val = 1;
        }

        //jumps
        if (row+2 <= 7 && col+2 <= 7 && main_tile[row+1][col+1]->get_piece() && !main_tile[row+2][col+2]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row+2][col+2]->get_tile_num());
            ret_val = 1;
        }

        if (row+2 <= 7 && col-2 >= 0 && main_tile[row+1][col-1]->get_piece() && !main_tile[row+2][col-2]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row+2][col-2]->get_tile_num());
            ret_val = 1;
        }

        if (row-2 >= 0 && col-2 >= 0 && main_tile[row-1][col-1]->get_piece() && !main_tile[row-2][col-2]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row-2][col-2]->get_tile_num());
            ret_val = 1;
        }

        if (row-2 >= 0 && col+2 <= 7 && main_tile[row-1][col+1]->get_piece() && !main_tile[row-2][col+2]->get_piece())
        {
            m_window->set_field_numbers_of_possible_moves (m_window->possible_number_of_moves++, main_tile[row-2][col+2]->get_tile_num());
            ret_val = 1;
        }
    }

    return ret_val;
}

int validation::check (tile *temp)
{
    Q_UNUSED (temp)
    return 0;
}

void validation::orange()
{
    for (int i=0; i<m_window->get_possible_number_of_moves(); i++)
    {
        main_tile[m_window->get_field_numbers_of_possible_moves(i)/8][m_window->get_field_numbers_of_possible_moves(i)%8]->setStyleSheet ("QLabel {background-color: orange;}");
    }
}
