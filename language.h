#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <iostream>

class language
{
private:
    static std::string game_name;
    static std::string game_menu_name;
    static std::string options_menu_name;
    static std::string new_game_menu_name;
    static std::string game_with_man_name;
    static std::string game_with_computer_name;
    static std::string game_rules_name;
    static std::string about_game_name;
    static std::string end_game_name;
    static std::string game_difficulty_name;
    static std::string easy_name;
    static std::string hard_name;
    static std::string play_with_the_computer_name;
    static std::string game_rules_text;
    static std::string about_game_text;
    static std::string close_text;
    static std::string player_text;
    static std::string end_turn_text;
    static std::string winner_text;
    static std::string draw_text;
    static std::string donation_text;

    language (std::string game_name, std::string game_menu_name, std::string options_menu_name, std::string new_game_menu_name, std::string game_with_man_name, std::string game_with_computer_name, std::string game_rules_name, std::string about_game_name, std::string end_game_name, std::string game_difficulty_name, std::string easy_name, std::string hard_name, std::string play_with_the_computer_name, std::string game_rules_text, std::string about_game_text, std::string close_text, std::string player_text, std::string end_turn_text, std::string winner_text, std::string donation_text, std::string draw_text)
    {
        language::game_name = game_name;
        language::game_menu_name = game_menu_name;
        language::options_menu_name = options_menu_name;
        language::new_game_menu_name = new_game_menu_name;
        language::game_with_man_name = game_with_man_name;
        language::game_with_computer_name = game_with_computer_name;
        language::game_rules_name = game_rules_name;
        language::about_game_name = about_game_name;
        language::end_game_name = end_game_name;
        language::game_difficulty_name = game_difficulty_name;
        language::easy_name = easy_name;
        language::hard_name = hard_name;
        language::play_with_the_computer_name = play_with_the_computer_name;
        language::game_rules_text = game_rules_text;
        language::about_game_text = about_game_text;
        language::close_text = close_text;
        language::player_text = player_text;
        language::end_turn_text = end_turn_text;
        language::winner_text = winner_text;
        language::draw_text = draw_text;
        language::donation_text = donation_text;
    }

public:
    static language& getInstance (std::string game_name, std::string game_menu_name, std::string options_menu_name, std::string new_game_menu_name, std::string game_with_man_name, std::string game_with_computer_name, std::string game_rules_name, std::string about_game_name, std::string end_game_name, std::string game_difficulty_name, std::string easy_name, std::string hard_name, std::string play_with_the_computer_name, std::string game_rules_text, std::string about_game_text, std::string close_text, std::string player_text, std::string end_turn_text, std::string winner_text, std::string draw_text, std::string donation_text)
    {
        static language instance (game_name, game_menu_name, options_menu_name, new_game_menu_name, game_with_man_name, game_with_computer_name, game_rules_name, about_game_name, end_game_name, game_difficulty_name, easy_name, hard_name, play_with_the_computer_name, game_rules_text, about_game_text, close_text, player_text, end_turn_text, winner_text, draw_text, donation_text);
        return instance;
    }

    static void set_en()
    {
        language::game_name = "Game Knight";
        language::game_menu_name = "Game";
        language::options_menu_name = "Options";
        language::new_game_menu_name = "New game";
        language::game_with_man_name = "Game with man";
        language::game_with_computer_name = "Game with computer";
        language::game_rules_name = "Game rules";
        language::about_game_name = "About game";
        language::end_game_name = "End game";
        language::game_difficulty_name = "Computer difficulty";
        language::easy_name = "Easy";
        language::hard_name = "Hard";
        language::play_with_the_computer_name = "Game with computer";
        language::game_rules_text = "The target of the game is moved Your pawns to Yours opponent start fields. The game begins person which play white pawns.\n\nDuring the turn, You can do one of two types of moves:\n- movement pawn to free field diagonally, which automatically end of the round\n- movement can do more then one, by jumping over the same pawn on diagonally through any colour pawn.\n\nAfter the end of the round, the second player can do movement. If the player moved pawns on the starting fields opponent,\nthe player don't do movement, and the second player have a point. The winner is the player who haven't points. The game can end in a draw.";
        language::about_game_text = "Game Knight, Version 1.0\n\nAuthor:\nPaweł Roszatycki\n\nLicence:\nCopyright (C) 2016\nThis program is free software: you can redistribute it and/or modify\nit under the terms of the GNU General Public License as published by\nthe Free Software Foundation, either version 3 of the License, or\n(at your option) any later version.\n\nThis program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the\nGNU General Public License for more details.\n\nYou should have received a copy of the GNU General Public License\nalong with this program. If not, see <http://www.gnu.org/licenses/>.\n\nKnight Game Copyright (C) 2016\nThis program comes with ABSOLUTELY NO WARRANTY.\nThis is free software, and you are welcome to redistribute it\nunder certain conditions.\n\nSource code:\nhttps://github.com/pawel112/cpp_knight_board_game/\n\nChessboard based on project CINES - Chess Is Not Entertainment Singally\n(https://github.com/tripples/CHESS-in-Qt)";
        language::close_text = "Close";
        language::player_text = "Player";
        language::end_turn_text = "End\nmovement";
        language::winner_text = "WINNER";
        language::draw_text = "DRAW";
        language::donation_text = "Donate through PayPal";
    }

    static void set_pl()
    {
        language::game_name = "Gra Skoczek";
        language::game_menu_name = "Gra";
        language::options_menu_name = "Opcje";
        language::new_game_menu_name = "Nowa gra";
        language::game_with_man_name = "Gra przeciwko człowiekowi";
        language::game_with_computer_name = "Gra przeciwko komputerowi";
        language::game_rules_name = "Zasady gry";
        language::about_game_name = "O grze";
        language::end_game_name = "Koniec gry";
        language::game_difficulty_name = "Poziom gry komputera";
        language::easy_name = "Łatwy";
        language::hard_name = "Trudny";
        language::play_with_the_computer_name = "Gra przeciwko komputerowi";
        language::game_rules_text = "Celem gry jest przesunięcie Twoich pionków na pola startowe przeciwnika. Grę zaczyna osoba grająca białymi pionkami.\n\nPodczas tury, możesz wykonać jeden z dwóch rodzajów ruchów:\n- przesunięcie pionka na wolne pole po przekątnej, które automatycznie kończy rundę\n- co najmniej jeden ruch, polegający na przeskoczenie tym samym pionkiem po przekątnej przez pionek dowolnego koloru.\n\nPo zakończeniu tury, drugi gracz może wykonać ruch. Jeżeli gracz przesunął swoje pionki na pola startowe przeciwnika,\ngracz nie wykonuje ruchu, a drugi gracz otrzymuje punkt. Zwycięzcą zostaje gracz, który nie posiada punktów. Gra może zakończyć się remisem.";
#ifdef __linux__
        language::about_game_text = "Gra Skoczek, wersja 1.0\n\nAutor:\nPaweł Roszatycki\n\nLicencja:\nPrawa autorskie (C) 2016\nTen program jest wolnym oprogramowaniem: program możesz rozprowadzać dalej\ni/lub modyfikować zgodnie z warunkami licencji „GNU General Public Licence”\nopublikowanych przez fundację „Free Software Foundation” w wersji 3. lub dowolnej nowszej wersji (wg twojej opcji).\n\nNiniejszy program rozpowszechniany jest z nadzieją, iż będzie on użyteczny,\nale BEZ JAKIEJKOLWIEK GWARANCJI; nawet bez domniemanej gwarancji.\nBEZ GWARANCJI HANDLOWEJ LUB PRZYDATNOŚC DO KONKRETNEGO CELU.\nZobacz licencję ”GNU General Public License” po więcej szczegółów.\n\nPowinieneś (powinnaś) otrzymać kopię licencji „GNU General Public License”\nwraz z tym programem. Jeśli nie, przeczytaj stronę <http://www.gnu.org/licenses/>.\n\nGra Skoczek Prawa autorskie (C) 2016\nTen program jest ABSOLUTNIE BEZ GWARANCJI. To jest wolne oprogramowanie\ni zachęcamy go do rozpowszechnienia pod pewnymi warunkami.\n\nKod źródłowy:\nhttps://github.com/pawel112/cpp_knight_board_game/\n\nSzachownica bazuje na projekcie \"CINES - Chess Is Not Entertainment Singally\" (https://github.com/tripples/CHESS-in-Qt)";
#else
        language::about_game_text = "Gra Skoczek, wersja 1.0\n\nAutor:\nPaweł Roszatycki\n\nLicencja:\nPrawa autorskie (C) 2016\nTen program jest wolnym oprogramowaniem: program możesz rozprowadzać dalej\ni/lub modyfikować zgodnie z warunkami licencji „GNU General Public Licence”\nopublikowanych przez fundację „Free Software Foundation” w wersji 3. lub dowolnej\nnowszej wersji (wg twojej opcji).\n\nNiniejszy program rozpowszechniany jest z nadzieją, iż będzie on użyteczny,\nale BEZ JAKIEJKOLWIEK GWARANCJI; nawet bez domniemanej gwarancji.\nBEZ GWARANCJI HANDLOWEJ LUB PRZYDATNOŚC DO KONKRETNEGO CELU.\nZobacz licencję ”GNU General Public License” po więcej szczegółów.\n\nPowinieneś (powinnaś) otrzymać kopię licencji „GNU General Public License”\nwraz z tym programem. Jeśli nie, przeczytaj stronę <http://www.gnu.org/licenses/>.\n\nGra Skoczek Prawa autorskie (C) 2016\nTen program jest ABSOLUTNIE BEZ GWARANCJI. To jest wolne oprogramowanie\ni zachęcamy go do rozpowszechnienia pod pewnymi warunkami.\n\nKod źródłowy:\nhttps://github.com/pawel112/cpp_knight_board_game/\n\nSzachownica bazuje na projekcie \"CINES - Chess Is Not Entertainment Singally\" (https://github.com/tripples/CHESS-in-Qt)";
#endif
        language::close_text = "Zamknij";
        language::player_text = "Gracz";
        language::end_turn_text = "Koniec\nruchu";
        language::winner_text = "ZWYCIĘSCA";
        language::draw_text = "REMIS";
        language::donation_text = "Darowizna poprzez PayPal";
    }

    static std::string get_game_name()
    {
        return language::game_name;
    }

    static std::string get_game_menu_name()
    {
        return language::game_menu_name;
    }

    static std::string get_options_menu_name()
    {
        return language::options_menu_name;
    }

    static std::string get_new_game_menu_name()
    {
        return language::new_game_menu_name;
    }

    static std::string get_game_with_man_name()
    {
        return language::game_with_man_name;
    }

    static std::string get_game_with_computer_name()
    {
        return language::game_with_computer_name;
    }

    static std::string get_game_rules_name()
    {
        return language::game_rules_name;
    }

    static std::string get_about_game_name()
    {
        return language::about_game_name;
    }

    static std::string get_end_game_name()
    {
        return language::end_game_name;
    }

    static std::string get_game_difficulty_name()
    {
        return language::game_difficulty_name;
    }

    static std::string get_hard_name()
    {
        return language::hard_name;
    }

    static std::string get_play_with_the_computer_name()
    {
        return language::play_with_the_computer_name;
    }

    static std::string get_game_rules_text()
    {
        return language::game_rules_text;
    }

    static std::string get_about_game_text()
    {
        return language::about_game_text;
    }

    static std::string get_close_text()
    {
        return language::close_text;
    }

    static std::string get_easy_name()
    {
        return language::easy_name;
    }

    static std::string get_player_text()
    {
        return language::player_text;
    }

    static std::string get_end_turn_text()
    {
        return language::end_turn_text;
    }

    static std::string get_winner_text()
    {
        return language::winner_text;
    }

    static std::string get_draw_text()
    {
        return language::draw_text;
    }

    static std::string get_donation_text()
    {
        return language::donation_text;
    }
};

#endif
