#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tile.h"
#include "choose_movement.h"
#include <QMainWindow>
#include <iostream>

namespace Ui
{
    class main_window;
}

class main_window: public QMainWindow
{
private:
    Ui::main_window *ui;
    bool now_jumping;
    bool clicked_field;
    bool change_points;
    bool now_first_player;
    bool without_changing_player;
    int jump_from_field[2];
    int field_numbers_of_possible_moves[60];
    tile *clicked_field_tile;
    Q_OBJECT

private slots:
    void on_action_End_game_triggered();
    void on_action_About_game_triggered();
    void on_action_Game_rules_triggered();
    void on_actionEasy_triggered (bool checked);
    void on_actionHard_triggered (bool checked);
    void on_actionGame_with_man_triggered();
    void on_actionGame_with_computer_triggered();
    void on_actionPlaying_with_the_computer_triggered (bool checked);
    void on_endButtonMovement_clicked();

public:
    explicit main_window (QWidget *parent = 0);
    void change_player_bold();
    void show_end_movement_button();
    void hide_end_movement_button();
    void player_1_name_bold (bool bold);
    void player_2_name_bold (bool bold);
    void set_player_1_points (std::string points);
    void set_player_2_points (std::string points);
    void set_play_with_computer_button (bool choise);
    void remove_orange();
    void remove_blue();
    void chess_board (QWidget *base_widget, tile *main_tile[8][8]);
    void set_pawns();
    void validate (tile *temp, int c);
    void end_turn();
    void set_now_jumping (bool value);
    void set_clicked_field (bool value);
    void set_change_points( bool value);
    void set_now_first_player (bool value);
    void set_without_changing_player (bool value);
    void set_field_numbers_of_possible_moves (int number, int value);
    void players_set_text (bool winner, bool winner1, bool winner2);
    std::string get_player_1_points();
    std::string get_player_2_points();
    int end_game();
    int get_jump_from_field(int number);
    int get_field_numbers_of_possible_moves(int number);
    int get_possible_number_of_moves();
    bool get_now_jumping();
    bool get_clicked_field();
    bool get_change_points();
    bool get_now_first_player();
    bool get_without_changing_player();
    ~main_window();

    int clicked_fields;
    int possible_number_of_moves;
    choose_movement *set_of_moves;
};


#endif
