#ifndef SETTINGS_H
#define SETTINGS_H

#include "main_window.h"
#include <iostream>

extern main_window *m_window;

class settings
{
private:
	static bool game_started;
	static bool game_with_computer;
	static bool player_1_choosed_white;
	static bool computer_difficulty;

    settings (bool game_started, bool game_with_computer, bool player_1_choosed_white, bool computer_difficulty)
	{
		settings::player_1_choosed_white = player_1_choosed_white;
		settings::game_started = game_started;
		settings::game_with_computer = game_with_computer;
		settings::computer_difficulty = computer_difficulty;
	}

public:
    static settings& getInstance (bool game_started, bool game_with_computer, bool player_1_choosed_white, bool computer_difficulty)
	{
        static settings instance (game_started, game_with_computer, player_1_choosed_white, computer_difficulty);
		return instance;
	}

    static void set_game_started (bool game_started)
	{
		settings::game_started = game_started;
	}

    static void set_game_with_computer (bool game_with_computer)
	{
		settings::game_with_computer = game_with_computer;
        m_window->set_play_with_computer_button (game_with_computer);
	}

    static void set_player_1_choosed_white (bool player_1_choosed_white)
	{
		settings::player_1_choosed_white = player_1_choosed_white;
	}

    static void set_computer_difficulty (bool computer_difficulty)
	{
		settings::computer_difficulty = computer_difficulty;
	}

	static bool get_game_started()
	{
		return settings::game_started;
	}

	static bool get_game_with_computer()
	{
		return settings::game_with_computer;
	}

	static bool get_player_1_choosed_white()
	{
		return settings::player_1_choosed_white;
	}

	static bool get_computer_difficulty()
	{
		return settings::computer_difficulty;
	}
};

#endif
