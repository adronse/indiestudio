/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/


#include "menu.hpp"

Menu::Menu()
{
    if (!this->music_menu_buff.loadFromFile(GET("menu_music.ogg")))
        exit(84);
    this->music_menu.setBuffer(this->music_menu_buff);
    this->music_menu.play();
}

Menu::~Menu()
{

}

void Menu::set_Menu(ISceneManager *sceneManager)
{
    this->menu_verif = true;
    this->select_menu_verif = false;
    this->sceneManager = sceneManager;
    this->guienv = this->sceneManager->getGUIEnvironment();

    this->guienv->addImage(this->sceneManager->getVideoDriver()->getTexture(GET("menu.jpg")), position2d<int>(0, 0));
    this->play_button = this->guienv->addButton(rect<irr::s32>(810, 420, 1100, 470), 0, GUI_ID_PLAY_BUTTON, L"Play Adventure");
    this->play_button->setDrawBorder(true);

    this->settings_button = this->guienv->addButton(rect<irr::s32>(810, 520, 1100, 570), 0, GUI_ID_SETTINGS_BUTTON, L"Settings");
    this->settings_button->setDrawBorder(true);

    this->exit_button = this->guienv->addButton(rect<irr::s32>(810, 620, 1100, 670), 0, GUI_ID_QUIT_BUTTON, L"EXIT");
    this->exit_button->setDrawBorder(true);
}

void Menu::set_settings()
{
    this->full_screen_button = this->guienv->addButton(rect<irr::s32>(810, 320, 1100, 370), 0, GUI_ID_FULL_SCREEN_BUTTON, L"Full Screen Mode");
    this->full_screen_button->setDrawBorder(true);

    this->window_1080_button = this->guienv->addButton(rect<irr::s32>(810, 420, 1100, 470), 0, GUI_ID_WINDOW_1080_BUTTON, L"Window Mode 1080px");
    this->window_1080_button->setDrawBorder(true);

    this->window_480_button = this->guienv->addButton(rect<irr::s32>(810, 520, 1100, 570), 0, GUI_ID_WINDOW_480_BUTTON, L"Window Mode 480px");
    this->window_480_button->setDrawBorder(true);

    this->back_menu_button = this->guienv->addButton(rect<irr::s32>(810, 620, 1100, 670), 0, GUI_ID_BACK_MENU_BUTTON, L"Back To Menu");
    this->back_menu_button->setDrawBorder(true);
}

void Menu::set_playing()
{
    this->start_button = this->guienv->addButton(rect<irr::s32>(960, 620, 1250, 670), 0, GUI_ID_START_BUTTON, L"START GAME");
    this->start_button->setDrawBorder(true);

    this->back_menu_button = this->guienv->addButton(rect<irr::s32>(660, 620, 950, 670), 0, GUI_ID_BACK_MENU_BUTTON, L"Back To Menu");
    this->back_menu_button->setDrawBorder(true);

    this->player_one_button = this->guienv->addButton(rect<irr::s32>(210, 420, 500, 470), 0, GUI_ID_PLAYER_ONE_BUTTON, L"HUMAN");
    this->player_one_button->setDrawBorder(true);
    this->verif_player_one_button = true;
    this->player_one_font = this->guienv->getBuiltInFont();

    this->player_two_button = this->guienv->addButton(rect<irr::s32>(610, 420, 900, 470), 0, GUI_ID_PLAYER_TWO_BUTTON, L"AI");
    this->player_two_button->setDrawBorder(true);
    this->verif_player_two_button = false;
    this->player_two_font = this->guienv->getBuiltInFont();
    
    this->player_three_button = this->guienv->addButton(rect<irr::s32>(1010, 420, 1300, 470), 0, GUI_ID_PLAYER_THREE_BUTTON, L"AI");
    this->player_three_button->setDrawBorder(true);
    this->verif_player_three_button = false;
    this->player_three_font = this->guienv->getBuiltInFont();

    this->player_four_button = this->guienv->addButton(rect<irr::s32>(1410, 420, 1700, 470), 0, GUI_ID_PLAYER_FOUR_BUTTON, L"AI");
    this->player_four_button->setDrawBorder(true);
    this->verif_player_four_button = false;
    this->player_four_font = this->guienv->getBuiltInFont();
}

void Menu::set_verif(bool verif)
{
    this->menu_verif = verif;
}

bool Menu::get_verif()
{
    return this->menu_verif;
}

void Menu::set_select_menu_verif(bool select_menu_verif)
{
    this->select_menu_verif = select_menu_verif;
}

bool Menu::get_select_menu_verif()
{
    return this->select_menu_verif;
}

void Menu::set_play_button(IGUIButton *play_button)
{
    this->play_button = play_button;
}

IGUIButton *Menu::get_play_button()
{
    return this->play_button;
}

void Menu::set_settings_button(IGUIButton *settings_button)
{
    this->settings_button = settings_button;
}

IGUIButton *Menu::get_settings_button()
{
    return this->settings_button;
}

void Menu::set_exit_button(IGUIButton *exit_button)
{
    this->exit_button = exit_button;
}

IGUIButton *Menu::get_exit_button()
{
    return this->exit_button;
}

void Menu::set_full_screen_button(IGUIButton *full_screen_button)
{
    this->full_screen_button = full_screen_button;
}

IGUIButton *Menu::get_full_screen_button()
{
    return this->full_screen_button;
}

void Menu::set_window_1080_button(IGUIButton *window_1080_button)
{
    this->window_1080_button = window_1080_button;
}

IGUIButton *Menu::get_window_1080_button()
{
    return this->window_1080_button;
}

void Menu::set_window_480_button(IGUIButton *window_480_button)
{
    this->window_480_button = window_480_button;
}

IGUIButton *Menu::get_window_480_button()
{
    return this->window_480_button;
}

void Menu::set_start_button(IGUIButton *start_button)
{
    this->start_button = start_button;
}

IGUIButton *Menu::get_start_button()
{
    return this->start_button;
}

void Menu::set_player_one_button(IGUIButton *player_one_button)
{
    this->player_one_button = player_one_button;
}

IGUIButton *Menu::get_player_one_button()
{
    return this->player_one_button;
}

void Menu::set_player_two_button(IGUIButton *player_two_button)
{
    this->player_two_button = player_two_button;
}

IGUIButton *Menu::get_player_two_button()
{
    return this->player_two_button;
}

void Menu::set_player_three_button(IGUIButton *player_three_button)
{
    this->player_three_button = player_three_button;
}

IGUIButton *Menu::get_player_three_button()
{
    return this->player_three_button;
}

void Menu::set_player_four_button(IGUIButton *player_four_button)
{
    this->player_four_button = player_four_button;
}

IGUIButton *Menu::get_player_four_button()
{
    return this->player_four_button;
}

void Menu::set_verif_player_one_button(bool verif_player_one_button)
{
    this->verif_player_one_button = verif_player_one_button;
}

bool Menu::get_verif_player_one_button()
{
    return this->verif_player_one_button;
}

void Menu::set_verif_player_two_button(bool verif_player_two_button)
{
    this->verif_player_two_button = verif_player_two_button;
}

bool Menu::get_verif_player_two_button()
{
    return this->verif_player_two_button;
}

void Menu::set_verif_player_three_button(bool verif_player_three_button)
{
    this->verif_player_three_button = verif_player_three_button;
}

bool Menu::get_verif_player_three_button()
{
    return this->verif_player_three_button;
}

void Menu::set_verif_player_four_button(bool verif_player_four_button)
{
    this->verif_player_four_button = verif_player_four_button;
}

bool Menu::get_verif_player_four_button()
{
    return this->verif_player_four_button;
}

void Menu::set_player_one_font(IGUIFont *player_one_font)
{
    this->player_one_font = player_one_font;
}

IGUIFont *Menu::get_player_one_font()
{
    return this->player_one_font;
}

void Menu::set_player_two_font(IGUIFont *player_two_font)
{
    this->player_two_font = player_two_font;
}

IGUIFont *Menu::get_player_two_font()
{
    return this->player_two_font;
}

void Menu::set_player_three_font(IGUIFont *player_three_font)
{
    this->player_three_font = player_three_font;
}

IGUIFont *Menu::get_player_three_font()
{
    return this->player_three_font;
}

void Menu::set_player_four_font(IGUIFont *player_four_font)
{
    this->player_four_font = player_four_font;
}

IGUIFont *Menu::get_player_four_font()
{
    return this->player_four_font;
}

void Menu::set_back_menu_button(IGUIButton *back_menu_button)
{
    this->back_menu_button = back_menu_button;
}

IGUIButton *Menu::get_back_menu_button()
{
    return this->back_menu_button;
}

void Menu::stop_music_menu()
{
    this->music_menu.stop();
}

void Menu::draw_menu()
{
    this->sceneManager->drawAll();
    this->guienv->drawAll();
}