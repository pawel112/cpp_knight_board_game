#include "choose_movement.h"
#include "settings.h"

extern main_window *m_window;
extern tile *main_tile[8][8];

choose_movement::choose_movement()
{
    clear_queue();
}

void choose_movement::do_movement (movement choosed_movement)
{
    main_tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->set_piece (1);
    main_tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->set_piece_color (0);
    main_tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->display ('P');

    main_tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->set_piece (0);
    main_tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->set_piece_color (0);
    main_tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->display ('n');

    main_tile[choosed_movement.get_movement_from1()][choosed_movement.get_movement_from2()]->setStyleSheet ("QLabel {background-color: blue;}");
    main_tile[choosed_movement.get_movement_to1()][choosed_movement.get_movement_to2()]->setStyleSheet ("QLabel {background-color: blue;}");

    if (!((choosed_movement.get_movement_throw11() == 0) && (choosed_movement.get_movement_throw12() == 0)))
    {
        main_tile[choosed_movement.get_movement_throw11()][choosed_movement.get_movement_throw12()]->setStyleSheet ("QLabel {background-color: blue;}");
    }

    if (!((choosed_movement.get_movement_throw21() == 0) && (choosed_movement.get_movement_throw22() == 0)))
    {
        main_tile[choosed_movement.get_movement_throw21()][choosed_movement.get_movement_throw22()]->setStyleSheet ("QLabel {background-color: blue;}");
    }
}

void choose_movement::add_movement (movement new_movement)
{
    this->movements.push (new_movement);
}

void choose_movement::clear_queue ()
{
    while (this->movements.empty() == false)
    {
        this->movements.top();
        this->movements.pop();
    }

    while (this->result.empty() == false)
    {
        this->result.top();
        this->result.pop();
    }
}

void choose_movement::finds_movements(tile *main_tile[8][8])
{
    if (settings::get_game_started() == false)
    {
        return;
    }

    for (int i=0; i<8; i++)
    //i omits the last row on the chessboard, because computer shouldn't choose movements involving backflow movements
    {
        for (int j=0; j<8; j++)
        {
            if ((!main_tile[i][j]->get_piece()) || (main_tile[i][j]->get_piece_color() != 0))
            {
                continue;
            }

            if ((i == 6) && (main_tile[i][j]->get_piece_color() == 0))
            {
                continue;
            }

            //1. weight 1
            //up, left
            if (main_tile[i][j]->get_row()-1 >= 0 && main_tile[i][j]->get_col()-1 >= 0 && !main_tile[main_tile[i][j]->get_row()-1][main_tile[i][j]->get_col()-1]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(-1, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()-1, main_tile[i][j]->get_col()-1));
            }

            //up, right
            if (main_tile[i][j]->get_row()-1 >= 0 && main_tile[i][j]->get_col()+1 <= 7 && !main_tile[main_tile[i][j]->get_row()-1][main_tile[i][j]->get_col()+1]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(-1, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()-1, main_tile[i][j]->get_col()+1));
            }

            //down, left
            if (main_tile[i][j]->get_row()+1 <= 7 && main_tile[i][j]->get_col()-1 >= 0 && !main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(1, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+1, main_tile[i][j]->get_col()-1));
            }

            //down, right
            if (main_tile[i][j]->get_row()+1 <= 7 && main_tile[i][j]->get_col()+1 <= 7 && !main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(1, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+1, main_tile[i][j]->get_col()+1));
            }


            //2. jumps - weight 2
            //down right x2
            if (main_tile[i][j]->get_row()+2 <= 7 && main_tile[i][j]->get_col()+2 <= 7 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(2, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2));
            }

            //down left x2
            if (main_tile[i][j]->get_row()+2 <= 7 && main_tile[i][j]->get_col()-2 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(2, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2));
            }

            //up right x2
            if (main_tile[i][j]->get_row()-2 >= 0 && main_tile[i][j]->get_col()+2 <= 7 && main_tile[main_tile[i][j]->get_row()-1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()-2][main_tile[i][j]->get_col()+2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(-2, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()-2, main_tile[i][j]->get_col()+2));
            }

            //up left x2
            if (main_tile[i][j]->get_row()-2 >= 0 && main_tile[i][j]->get_col()-2 >= 0 && main_tile[main_tile[i][j]->get_row()-1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()-2][main_tile[i][j]->get_col()-2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(-2, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()-2, main_tile[i][j]->get_col()-2));
            }


            //3. jumps - weight 4 (skipping movements weights below zero)
            //down right x4
            if (main_tile[i][j]->get_row()+4 <= 7 && main_tile[i][j]->get_col()+4 <= 7 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()+3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()+4]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(4, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()+4, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2));
            }

            //down left x4
            if (main_tile[i][j]->get_row()+4 <= 7 && main_tile[i][j]->get_col()-4 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()-3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()-4]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(4, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()-4, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2));
            }

            //down right x2, down left x2
            if (main_tile[i][j]->get_row()+4 <= 7 && main_tile[i][j]->get_col()+2 <= 7 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(4, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2));
            }

            //down left x2, down right x2
            if (main_tile[i][j]->get_row()+4 <= 7 && main_tile[i][j]->get_col()-2 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(4, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2));
            }


            //4. jumps - weight 6 (skipping movements weights below zero)
            //down right x6
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()+6 <= 7 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()+3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()+4]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()+5]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()+6]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()+6, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()+4));
            }

            //down left x6
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()-6 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()-3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()-4]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()-5]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()-6]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()-6, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()-4));
            }

            //down right x4, down left x2
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()+4 <= 7 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()+3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()+4]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()+3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()+2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()+4));
            }

            //down left x4, down right x2
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()-4 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()-3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()-4]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()-3]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()-2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()-4));
            }

            //down right x2, down left x4
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()+2 <= 7 && main_tile[i][j]->get_col()-2 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()-2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()));
            }

            //down left x2, down right x4
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()+2 <= 7 && main_tile[i][j]->get_col()-2 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()+2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()));
            }

            //down right x2, down left x2, down right x2
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()+2 <= 7 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()+2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()+1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()+2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()+2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()));
            }

            //down left x2, down right x2, down left x2
            if (main_tile[i][j]->get_row()+6 <= 7 && main_tile[i][j]->get_col()-2 >= 0 && main_tile[main_tile[i][j]->get_row()+1][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+2][main_tile[i][j]->get_col()-2]->get_piece() && main_tile[main_tile[i][j]->get_row()+3][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+4][main_tile[i][j]->get_col()]->get_piece() && main_tile[main_tile[i][j]->get_row()+5][main_tile[i][j]->get_col()-1]->get_piece() && !main_tile[main_tile[i][j]->get_row()+6][main_tile[i][j]->get_col()-2]->get_piece())
            {
                m_window->set_of_moves->add_movement(movement(6, main_tile[i][j]->get_row(), main_tile[i][j]->get_col(), main_tile[i][j]->get_row()+6, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+2, main_tile[i][j]->get_col()-2, main_tile[i][j]->get_row()+4, main_tile[i][j]->get_col()));
            }
        }
    }
}

movement choose_movement::return_movement ()
{
    if (this->movements.size() == 0)
    {
        clear_queue();
        return movement();
    }
    else if (this->movements.size() == 1)
    {
        movement return_movement = this->movements.top();
        clear_queue();
        return return_movement;
    }
    else if (settings::get_computer_difficulty()==true)
    {
        movement temp = movements.top();
        int weight = temp.get_movement_weight();

        while (this->movements.empty() == false)
        {
            movement new_movement = this->movements.top();
            this->movements.pop();

            if (new_movement.get_movement_weight() == weight)
            {
                this->result.push(new_movement);
            }
            else
            {
                break;
            }
        }

        int result_size = (int)this->result.size();
        int choosed_movement = rand()%result_size;

        for (int i=0; i<choosed_movement-1; i++)
        {
            this->result.top();
            this->result.pop();
        }
        movement return_movement = this->result.top();
        clear_queue();
        return return_movement;
    }
    else
    {
        int movements_size = (int)this->movements.size();
        int choosed_movement = rand()%movements_size;
        movement return_movement = this->movements.top();

        for (int i=0; i<choosed_movement; i++)
        {
            return_movement = this->movements.top();
            this->movements.pop();
        }

        clear_queue();
        return return_movement;
    }
}
