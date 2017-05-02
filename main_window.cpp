#include "main_window.h"
#include "about_window.h"
#include "rules_window.h"
#include "ui_main_window.h"
#include "settings.h"
#include "language.h"
#include "tile.h"
#include "choose_movement.h"
#include "validation.h"

main_window *m_window = NULL;
tile *main_tile[8][8] = { { NULL } };

main_window::main_window (QWidget *parent):
    QMainWindow (parent),
    ui (new Ui::main_window)
    {
        ui->setupUi (this);
        chess_board (this, main_tile);
        this->setWindowTitle(QString::fromStdString(language::get_game_name()));
        this->statusBar()->setSizeGripEnabled(false);
        this->setFixedWidth(this->width());
        this->setFixedHeight(this->height());
        ui->menu_New_game->setTitle(QString::fromStdString(language::get_new_game_menu_name()));
        ui->actionGame_with_computer->setText(QString::fromStdString(language::get_game_with_computer_name()));
        ui->actionGame_with_man->setText(QString::fromStdString(language::get_game_with_man_name()));
        ui->actionEasy->setText(QString::fromStdString(language::get_easy_name()));
        ui->actionHard->setText(QString::fromStdString(language::get_hard_name()));
        ui->menuGame->setTitle(QString::fromStdString(language::get_game_menu_name()));
        ui->menuOptions->setTitle(QString::fromStdString(language::get_options_menu_name()));
        ui->action_About_game->setText(QString::fromStdString(language::get_about_game_name()));
        ui->action_Game_rules->setText(QString::fromStdString(language::get_game_rules_name()));
        ui->action_End_game->setText(QString::fromStdString(language::get_end_game_name()));
        ui->menuComputer_difficulty->setTitle(QString::fromStdString(language::get_game_difficulty_name()));
        ui->actionPlaying_with_the_computer->setText(QString::fromStdString(language::get_play_with_the_computer_name()));
        ui->endButtonMovement->setText(QString::fromStdString(language::get_end_turn_text()));
        ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
        ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
        ui->player_1_points->setText(QString::fromStdString("0"));
        ui->player_2_points->setText(QString::fromStdString("0"));
        hide_end_movement_button();

        now_jumping = false;
        clicked_field = false;
        change_points = false;
        now_first_player = true;
        without_changing_player = false;
        clicked_fields = 0;
        possible_number_of_moves = 0;
        jump_from_field[0] = 0;
        jump_from_field[1] = 0;
        clicked_field_tile = NULL;
        set_of_moves = new choose_movement();
    }

main_window::~main_window()
{
    delete ui;
}

void main_window::on_action_End_game_triggered()
{
    this->close();
}

void main_window::on_action_About_game_triggered()
{
    about_window *w = new about_window();
    w->show();
}

void main_window::on_action_Game_rules_triggered()
{
    rules_window *w = new rules_window();
    w->show();
}

void main_window::on_actionEasy_triggered(bool checked)
{
    if ((settings::get_game_started() == false) || (settings::get_game_with_computer() == false))
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(false);
        return;
    }

    if (checked == true)
    {
        settings::set_computer_difficulty (false);
        ui->actionEasy->setChecked(true);
        ui->actionHard->setChecked(false);
    }
    else
    {
        settings::set_computer_difficulty (true);
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(true);
    }
}

void main_window::on_actionHard_triggered(bool checked)
{
    if ((settings::get_game_started() == false) || (settings::get_game_with_computer() == false))
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(false);
        return;
    }

    if (checked == true)
    {
        settings::set_computer_difficulty (true);
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(true);
    }
    else
    {
        settings::set_computer_difficulty (false);
        ui->actionEasy->setChecked(true);
        ui->actionHard->setChecked(false);
    }
}

void main_window::on_actionGame_with_man_triggered()
{
    for (int i=0; i<60; i++)
    {
        field_numbers_of_possible_moves[i] = 0;
    }

    change_points = false;
    clicked_fields = false;
    now_first_player = true;
    without_changing_player = false;
    settings::set_game_started (true);
    settings::set_game_with_computer (false);
    settings::set_player_1_choosed_white (true);
    settings::set_computer_difficulty (false);
    ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
    ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
    ui->player_1_points->setText(QString::fromStdString("0"));
    ui->player_2_points->setText(QString::fromStdString("0"));
    player_1_name_bold (true);
    player_2_name_bold (false);
    players_set_text (false, false, false);
    show_end_movement_button();
    set_pawns();
}

void main_window::on_actionGame_with_computer_triggered()
{
    for (int i=0; i<60; i++)
    {
        field_numbers_of_possible_moves[i] = 0;
    }

    change_points = false;
    clicked_fields = false;
    now_first_player = true;
    without_changing_player = false;
    settings::set_game_started (true);
    settings::set_game_with_computer (true);
    settings::set_player_1_choosed_white (true);
    settings::set_computer_difficulty (true);
    ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
    ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
    ui->player_1_points->setText(QString::fromStdString("0"));
    ui->player_2_points->setText(QString::fromStdString("0"));
    player_1_name_bold (true);
    player_2_name_bold (false);
    players_set_text (false, false, false);
    show_end_movement_button();
    on_actionHard_triggered (true);
    set_pawns();
}

void main_window::on_actionPlaying_with_the_computer_triggered (bool checked)
{
    if (checked == false)
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(false);
    }
    else
    {
        ui->actionEasy->setChecked(false);
        ui->actionHard->setChecked(true);
    }

    settings::set_game_with_computer (checked);
}

void main_window::on_endButtonMovement_clicked()
{
    if (settings::get_game_started() == false)
    {
        return;
    }

    remove_blue();
    if (clicked_field == true)
    {
        clicked_field = false;
    }
    end_turn();
}

void main_window::change_player_bold()
{
    if (now_first_player == true)
    {
        player_1_name_bold (true);
        player_2_name_bold (false);
    }
    else
    {
        player_1_name_bold (false);
        player_2_name_bold (true);
    }
}

void main_window::show_end_movement_button()
{
   ui->endButtonMovement->show();
}

void main_window::hide_end_movement_button()
{
    ui->endButtonMovement->hide();
}

void main_window::player_1_name_bold (bool bold)
{
    if (bold == true)
    {
        ui->player_1_name->setStyleSheet(" font-weight: bold; ");
    }
    else
    {
        ui->player_1_name->setStyleSheet(" font-weight: none; ");
    }
}

void main_window::player_2_name_bold (bool bold)
{
    if (bold == true)
    {
        ui->player_2_name->setStyleSheet(" font-weight: bold; ");
    }
    else
    {
        ui->player_2_name->setStyleSheet(" font-weight: none; ");
    }
}

void main_window::players_set_text (bool winner, bool winner1, bool winner2)
{
    if (winner == true)
    {
        if ((winner1 == true) && (winner2 == false))
        {
            ui->player_1_name->setText(QString::fromStdString(language::get_winner_text()));
            player_1_name_bold (true);
            player_2_name_bold (false);
        }
        else if ((winner1 == false) && (winner2 == true))
        {
            ui->player_2_name->setText(QString::fromStdString(language::get_winner_text()));
            player_1_name_bold (false);
            player_2_name_bold (true);
        }
        else if ((winner1 == true) && (winner2 == true))
        {
            ui->player_1_name->setText(QString::fromStdString(language::get_draw_text()));
            ui->player_2_name->setText(QString::fromStdString(language::get_draw_text()));
            player_1_name_bold (true);
            player_2_name_bold (true);
        }
    }
    else
    {
        ui->player_1_name->setText(QString::fromStdString(language::get_player_text()+" 1"));
        ui->player_2_name->setText(QString::fromStdString(language::get_player_text()+" 2"));
    }
}

void main_window::set_player_1_points (std::string points)
{
    ui->player_1_points->setText(QString::fromStdString(points));
}

void main_window::set_player_2_points (std::string points)
{
    ui->player_2_points->setText(QString::fromStdString(points));
}

void main_window::set_play_with_computer_button (bool choise)
{
    ui->actionPlaying_with_the_computer->setChecked(choise);
}

std::string main_window::get_player_1_points ()
{
    return ui->player_1_points->text().toStdString();
}

std::string main_window::get_player_2_points ()
{
    return ui->player_2_points->text().toStdString();
}

void main_window::remove_orange ()
{
    for (int i=0; i<possible_number_of_moves; i++)
    {
        main_tile[field_numbers_of_possible_moves[i]/8][field_numbers_of_possible_moves[i]%8]->tile_display ();
    }
}

void main_window::remove_blue ()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            main_tile[i][j]->tile_display();
        }
    }
}

void main_window::chess_board (QWidget *base_widget, tile *main_tile[8][8])
{
    QLabel *outLabel = new QLabel (base_widget);
    outLabel->setGeometry (682, 55, 20, 512);
    outLabel->setStyleSheet ("QLabel { background-color :rgb(170, 170, 127); color : black; }");
    QLabel *outLabel2 = new QLabel (base_widget);
    outLabel2->setGeometry (150, 55, 20, 512);
    outLabel2->setStyleSheet ("QLabel { background-color :rgb(170, 170, 127); color : black; }");
    QLabel *outLabel3 = new QLabel (base_widget);
    outLabel3->setGeometry (150, 35, 552, 20);
    outLabel3->setStyleSheet ("QLabel { background-color :rgb(170, 170, 127); color : black; }");
    QLabel *outLabel4 = new QLabel (base_widget);
    outLabel4->setGeometry (150, 567, 552, 20);
    outLabel4->setStyleSheet ("QLabel { background-color :rgb(170, 170, 127); color : black; }");

    //create 64 tiles
    int ver = 55;
    int hor = 0;
    int k = 0;
    for (int i=0; i<8; i++)
    {
        hor = 170;
        for (int j=0; j<8; j++)
        {
            main_tile[i][j] = new tile (base_widget);
            main_tile[i][j]->set_tile_color ((i+j)%2);
            main_tile[i][j]->set_piece (0);
            main_tile[i][j]->set_row (i);
            main_tile[i][j]->set_col (j);
            main_tile[i][j]->set_tile_num (k++);
            main_tile[i][j]->tile_display ();
            main_tile[i][j]->setGeometry (hor, ver, 64, 64);
            hor += 64;
        }
        ver += 64;
    }
    set_pawns();
}

void main_window::set_pawns()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            main_tile[i][j]->set_tile_color ((i+j)%2);
            main_tile[i][j]->setStyleSheet ("QLabel {background-color: green;}");
            main_tile[i][j]->set_piece (0);
            main_tile[i][j]->set_row (i);
            main_tile[i][j]->set_col (j);
            main_tile[i][j]->set_piece_color (0);
            main_tile[i][j]->display ('n');
            main_tile[i][j]->tile_display ();
        }
    }

    //white pawns
    for (int j=0; j<8; j++)
    {
        main_tile[0][j]->set_piece (1);
        main_tile[0][j]->set_piece_color (0);
        main_tile[0][j]->display ('P');
    }
    for (int j=0; j<8; j++)
    {
        main_tile[1][j]->set_piece (1);
        main_tile[1][j]->set_piece_color (0);
        main_tile[1][j]->display ('P');
    }

    //black pawns
    for (int j=0; j<8; j++)
    {
        main_tile[7][j]->set_piece (1);
        main_tile[7][j]->set_piece_color (1);
        main_tile[7][j]->display ('P');
    }
    for (int j=0; j<8; j++)
    {
        main_tile[6][j]->set_piece (1);
        main_tile[6][j]->set_piece_color (1);
        main_tile[6][j]->display ('P');
    }
}

void main_window::validate (tile *temp, int c)
{
    int ret_value = 0;
    validation *field_to_valid = new validation();

    if (c == 1)
    {
        if (temp->get_piece() && (temp->get_piece_color() == m_window->now_first_player))
        {
            ret_value = field_to_valid->chooser (temp);

            if (ret_value)
            {
                temp->setStyleSheet ("QLabel {background-color: green;}");
                clicked_field_tile = temp;
                jump_from_field[0] = temp->get_row();
                jump_from_field[1] = temp->get_col();
            }
            else
            {
                clicked_fields = false;
            }
        }
        else
        {
            clicked_fields = false;
        }
    }
    else
    {
        if (temp->get_tile_num() == clicked_field_tile->get_tile_num())
        {
            clicked_field_tile->tile_display ();
            remove_orange ();
            possible_number_of_moves = 0;
            clicked_fields = false;
        }

        for (int i=0; i<possible_number_of_moves; i++)
        {
            if (temp->get_tile_num() == field_numbers_of_possible_moves[i])
            {
                clicked_field_tile->set_piece (0);
                temp->set_piece (1);

                temp->set_piece_color (clicked_field_tile->get_piece_color());
                temp->set_piece_name (clicked_field_tile->get_piece_name());

                clicked_field_tile->display (clicked_field_tile->get_piece_name());
                temp->display (clicked_field_tile->get_piece_name());

                clicked_field_tile->tile_display ();
                temp->tile_display ();

                ret_value = field_to_valid->check (clicked_field_tile);

                remove_orange ();
                possible_number_of_moves = 0;

                if (abs (temp->get_row() - jump_from_field[0]) == 1)
                {
                    jump_from_field[0] = 0;
                    jump_from_field[1] = 0;

                    end_turn();
                }
                else
                {
                    jump_from_field[0] = temp->get_row();
                    jump_from_field[1] = temp->get_col();
                    now_jumping = true;
                }
                clicked_fields = false;
            }
            else
            {
                clicked_fields = true;
            }
        }
    }
}

void main_window::end_turn()
{
    set_of_moves->clear_queue();
    if (!((jump_from_field[0] == 0) && (jump_from_field[1] == 0)))
    {
        if (main_tile[jump_from_field[0]][jump_from_field[1]]->get_tile_color() == false)
        {
            main_tile[jump_from_field[0]][jump_from_field[1]]->setStyleSheet ("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,85,127);}");
        }
        else
        {
            main_tile[jump_from_field[0]][jump_from_field[1]]->setStyleSheet ("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
        }
    }

    remove_orange ();
    possible_number_of_moves = 0;
    clicked_fields = false;

    if (without_changing_player == false)
    {
        now_first_player = (now_first_player+1)%2;
    }

    if (end_game() == 0)
    {
        m_window->change_player_bold();
    }
    else if ((end_game() == 1) && (settings::get_game_with_computer() == false))
    {
        //turn without change
        //don't change the players bold
        if (change_points == true)
        {
            set_player_2_points (std::to_string(stoi(get_player_2_points())+1));
        }
        else
        {
            change_points = true;
        }

        without_changing_player = true;
        player_1_name_bold (false);
        player_2_name_bold (true);
        players_set_text (true, true, false);
    }
    else if ((end_game() == 1) && (settings::get_game_with_computer() == true))
    {
        set_player_2_points (std::to_string(stoi(get_player_2_points())+1));
        set_of_moves->finds_movements(main_tile);
        movement temp_movement = set_of_moves->return_movement();
        if (temp_movement.get_movement_weight() != 0)
        {
            set_of_moves->do_movement (temp_movement);
        }
        end_turn();
        player_1_name_bold (false);
        player_2_name_bold (true);
        players_set_text (true, true, false);
    }
    else if (end_game() == 2)
    {
        //turn without change
        //don't change the players bold
        set_player_1_points (std::to_string(stoi(get_player_1_points())+1));
        without_changing_player = true;
        player_1_name_bold (true);
        player_2_name_bold (false);
        players_set_text (true, false, true);
    }
    else
    {
        if (settings::get_game_with_computer() == true)
        {
            remove_blue();
        }

        settings::set_game_started(false);
        hide_end_movement_button();

        if (stoi(get_player_1_points()) < stoi(get_player_2_points()))
        {
            player_1_name_bold (true);
            player_2_name_bold (false);
        }
        else if (stoi(get_player_1_points()) > stoi(get_player_2_points()))
        {
            player_1_name_bold (false);
            player_2_name_bold (true);
        }
        else
        {
            player_1_name_bold (true);
            player_2_name_bold (true);
            players_set_text (true, true, true);
        }

        hide_end_movement_button();

        jump_from_field[0] = 0;
        jump_from_field[1] = 0;
        now_jumping = false;
        return;
    }

    jump_from_field[0] = 0;
    jump_from_field[1] = 0;
    now_jumping = false;
    show_end_movement_button();

    if ((now_first_player == false) && (settings::get_game_with_computer() == true))
    {
        set_of_moves->finds_movements(main_tile);
        movement temp_movement = set_of_moves->return_movement();
        if (temp_movement.get_movement_weight() != 0)
        {
            set_of_moves->do_movement (temp_movement);
        }
        end_turn();
    }
}

int main_window::end_game()
{
    bool white_pawns_wins = false;
    bool black_pawns_wins = false;

    //check black
    if ((main_tile[0][0]->get_piece() == 1) && (main_tile[0][0]->get_piece_color() == 1) && (main_tile[0][1]->get_piece() == 1) && (main_tile[0][1]->get_piece_color() == 1) && (main_tile[0][2]->get_piece() == 1) && (main_tile[0][2]->get_piece_color() == 1) && (main_tile[0][3]->get_piece() == 1) && (main_tile[0][3]->get_piece_color() == 1) && (main_tile[0][4]->get_piece() == 1) && (main_tile[0][4]->get_piece_color() == 1) && (main_tile[0][5]->get_piece() == 1) && (main_tile[0][5]->get_piece_color() == 1) && (main_tile[0][6]->get_piece() == 1) && (main_tile[0][6]->get_piece_color() == 1) && (main_tile[0][7]->get_piece() == 1) && (main_tile[0][7]->get_piece_color() == 1) && (main_tile[1][0]->get_piece() == 1) && (main_tile[1][0]->get_piece_color() == 1) && (main_tile[1][1]->get_piece() == 1) && (main_tile[1][1]->get_piece_color() == 1) && (main_tile[1][2]->get_piece() == 1) && (main_tile[1][2]->get_piece_color() == 1) && (main_tile[1][3]->get_piece() == 1) && (main_tile[1][3]->get_piece_color() == 1) && (main_tile[1][4]->get_piece() == 1) && (main_tile[1][4]->get_piece_color() == 1) && (main_tile[1][5]->get_piece() == 1) && (main_tile[1][5]->get_piece_color() == 1) && (main_tile[1][6]->get_piece() == 1) && (main_tile[1][6]->get_piece_color() == 1) && (main_tile[1][7]->get_piece() == 1) && (main_tile[1][7]->get_piece_color() == 1))
    {
        black_pawns_wins = true;
    }

    //check white
    if ((main_tile[6][0]->get_piece() == 1) && (main_tile[6][0]->get_piece_color() == 0) && (main_tile[6][1]->get_piece() == 1) && (main_tile[6][1]->get_piece_color() == 0) && (main_tile[6][2]->get_piece() == 1) && (main_tile[6][2]->get_piece_color() == 0) && (main_tile[6][3]->get_piece() == 1) && (main_tile[6][3]->get_piece_color() == 0) && (main_tile[6][4]->get_piece() == 1) && (main_tile[6][4]->get_piece_color() == 0) && (main_tile[6][5]->get_piece() == 1) && (main_tile[6][5]->get_piece_color() == 0) && (main_tile[6][6]->get_piece() == 1) && (main_tile[6][6]->get_piece_color() == 0) && (main_tile[6][7]->get_piece() == 1) && (main_tile[6][7]->get_piece_color() == 0) && (main_tile[7][0]->get_piece() == 1) && (main_tile[7][0]->get_piece_color() == 0) && (main_tile[7][1]->get_piece() == 1) && (main_tile[7][1]->get_piece_color() == 0) && (main_tile[7][2]->get_piece() == 1) && (main_tile[7][2]->get_piece_color() == 0) && (main_tile[7][3]->get_piece() == 1) && (main_tile[7][3]->get_piece_color() == 0) && (main_tile[7][4]->get_piece() == 1) && (main_tile[7][4]->get_piece_color() == 0) && (main_tile[7][5]->get_piece() == 1) && (main_tile[7][5]->get_piece_color() == 0) && (main_tile[7][6]->get_piece() == 1) && (main_tile[7][6]->get_piece_color() == 0) && (main_tile[7][7]->get_piece() == 1) && (main_tile[7][7]->get_piece_color() == 0))
    {
        white_pawns_wins = true;
    }

    if ((white_pawns_wins == true) && (black_pawns_wins == true))
    {
        return 3;
    }

    if ((white_pawns_wins == true) && (black_pawns_wins == false))
    {
        return 2;
    }

    if ((white_pawns_wins == false) && (black_pawns_wins == true))
    {
        return 1;
    }

    if ((white_pawns_wins == false) && (black_pawns_wins == false))
    {
        return 0;
    }
    return 0;
}

bool main_window::get_now_jumping()
{
    return now_jumping;
}

void main_window::set_now_jumping (bool value)
{
    now_jumping = value;
}

bool main_window::get_clicked_field()
{
    return clicked_field;
}

void main_window::set_clicked_field (bool value)
{
    clicked_field = value;
}

bool main_window::get_change_points()
{
    return change_points;
}

void main_window::set_change_points (bool value)
{
    change_points = value;
}

bool main_window::get_now_first_player()
{
    return now_first_player;
}

void main_window::set_now_first_player (bool value)
{
    now_first_player = value;
}

bool main_window::get_without_changing_player()
{
    return without_changing_player;
}

void main_window::set_without_changing_player (bool value)
{
    without_changing_player = value;
}

int main_window::get_jump_from_field (int number)
{
    return jump_from_field[number];
}

void main_window::set_field_numbers_of_possible_moves (int number, int value)
{
    field_numbers_of_possible_moves[number] = value;
}

int main_window::get_field_numbers_of_possible_moves (int number)
{
    return field_numbers_of_possible_moves[number];
}

int main_window::get_possible_number_of_moves()
{
    return possible_number_of_moves;
}
