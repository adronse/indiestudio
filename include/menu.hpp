/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include <iostream>
#include "irrlicht.h"
#include "core.hpp"
#include <SFML/Audio.hpp>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifndef menu_hpp
#define menu_hpp

class Menu {
    public:
        Menu();
        ~Menu();
        void set_Menu(ISceneManager *);
        void set_settings();
        void set_playing();
        void draw_menu();
        void set_select_menu_verif(bool);
        bool get_select_menu_verif();
        void set_verif(bool);
        bool get_verif();
        void set_play_button(IGUIButton *);
        IGUIButton *get_play_button();
        void set_settings_button(IGUIButton *);
        IGUIButton *get_settings_button();
        void set_exit_button(IGUIButton *);
        IGUIButton *get_exit_button();
        void set_full_screen_button(IGUIButton *);
        IGUIButton *get_full_screen_button();
        void set_window_1080_button(IGUIButton *);
        IGUIButton *get_window_1080_button();
        void set_window_480_button(IGUIButton *);
        IGUIButton *get_window_480_button();
        void set_back_menu_button(IGUIButton *);
        IGUIButton *get_back_menu_button();
        void set_start_button(IGUIButton *);
        IGUIButton *get_start_button();
        void set_player_one_button(IGUIButton *);
        IGUIButton *get_player_one_button();
        void set_player_two_button(IGUIButton *);
        IGUIButton *get_player_two_button();
        void set_player_three_button(IGUIButton *);
        IGUIButton *get_player_three_button();
        void set_player_four_button(IGUIButton *);
        IGUIButton *get_player_four_button();
        void set_verif_player_one_button(bool);
        bool get_verif_player_one_button();
        void set_verif_player_two_button(bool);
        bool get_verif_player_two_button();
        void set_verif_player_three_button(bool);
        bool get_verif_player_three_button();
        void set_verif_player_four_button(bool);
        bool get_verif_player_four_button();
        void set_player_one_font(IGUIFont *);
        IGUIFont *get_player_one_font();
        void set_player_two_font(IGUIFont *);
        IGUIFont *get_player_two_font();
        void set_player_three_font(IGUIFont *);
        IGUIFont *get_player_three_font();
        void set_player_four_font(IGUIFont *);
        IGUIFont *get_player_four_font();
        void stop_music_menu();
    protected:
    private:
        IGUIEnvironment *guienv;
        IGUIButton *play_button;
        IGUIButton *settings_button;
        IGUIButton *exit_button;
        IGUIButton *full_screen_button;
        IGUIButton *window_1080_button;
        IGUIButton *window_480_button;
        IGUIButton *back_menu_button;
        IGUIButton *start_button;
        IGUIButton *player_one_button;
        IGUIButton *player_two_button;
        IGUIButton *player_three_button;
        IGUIButton *player_four_button;
        IGUIFont *player_one_font;
        IGUIFont *player_two_font;
        IGUIFont *player_three_font;
        IGUIFont *player_four_font;
        ISceneManager *sceneManager;
        sf::SoundBuffer music_menu_buff;
        sf::Sound music_menu;
        bool menu_verif;
        bool select_menu_verif;
        bool verif_player_one_button;
        bool verif_player_two_button;
        bool verif_player_three_button;
        bool verif_player_four_button;
};

#endif /* !menu_hpp */
