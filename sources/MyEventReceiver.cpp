/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#include "MyEventReceiver.hpp"
#include <unistd.h>

bool MyEventReceiver::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        IGUIEnvironment* env = this->context.device->getGUIEnvironment();
        switch(event.GUIEvent.EventType) {
            case EGET_BUTTON_CLICKED:
                switch(id) {
                    case GUI_ID_QUIT_BUTTON:
                        this->context.device->closeDevice();
                        printf("exit\n");
                        return true;
                    case GUI_ID_PLAY_BUTTON:
                        printf("play\n");
                        this->context.menu->get_play_button()->remove();
                        this->context.menu->get_settings_button()->remove();
                        this->context.menu->get_exit_button()->remove();
                        this->context.menu->set_playing();
                        this->context.menu->set_select_menu_verif(true);
                        return true;
                    case GUI_ID_START_BUTTON:
                        if (this->context.menu->get_verif() == true) {
                            printf("play\n");
                            this->context.menu->stop_music_menu();
                            this->context.menu->set_verif(false);
                            this->context.map->set_case();
                            this->context.game->set_verif_player_one(this->context.menu->get_verif_player_one_button());
                            this->context.game->set_verif_player_two(this->context.menu->get_verif_player_two_button());
                            this->context.game->play_music_game();
                            this->context.game->launchThread();
                        }
                        return true;
                    case GUI_ID_SETTINGS_BUTTON:
                        printf("settings\n");
                        this->context.menu->get_play_button()->remove();
                        this->context.menu->get_settings_button()->remove();
                        this->context.menu->get_exit_button()->remove();
                        this->context.menu->set_settings();
                        return true;
                    case GUI_ID_FULL_SCREEN_BUTTON:
                        printf("full screen\n");
                        return true;
                    case GUI_ID_WINDOW_1080_BUTTON: {
                        printf("window 1080\n");
                        this->context.device->closeDevice();
                        IrrlichtDevice *device1080 = createDevice(context.driverType, dimension2d<u32>(1920,1080), 32, false, true, false, 0);
                        context.core->setDevice(device1080);
                        return true;
                    }
                    case GUI_ID_WINDOW_480_BUTTON: {
                        printf("window 480\n");
                        this->context.device->closeDevice();
                        IrrlichtDevice *device480 = createDevice(context.driverType, dimension2d<u32>(720,480), 32, false, true, false, 0);
                        context.core->setDevice(device480);
                        return true;
                    }
                    case GUI_ID_BACK_MENU_BUTTON:
                        printf("back_menu\n");
                        if (this->context.menu->get_select_menu_verif() == false) {
                            this->context.menu->get_full_screen_button()->remove();
                            this->context.menu->get_window_1080_button()->remove();
                            this->context.menu->get_window_480_button()->remove();
                        }
                        else {
                            this->context.menu->get_player_one_button()->remove();
                            this->context.menu->get_player_two_button()->remove();
                            this->context.menu->get_player_three_button()->remove();
                            this->context.menu->get_player_four_button()->remove();
                            this->context.menu->get_start_button()->remove();
                        }
                        this->context.menu->set_select_menu_verif(false);
                        this->context.menu->get_back_menu_button()->remove();
                        this->context.menu->set_Menu(this->context.device->getSceneManager());
                        return true;
                    case GUI_ID_PLAYER_ONE_BUTTON:
                        if (this->context.menu->get_verif_player_one_button() == false) {
                            this->context.menu->get_player_one_button()->setText(L"HUMAN");
                            this->context.menu->set_verif_player_one_button(true);
                            printf("Player One is real player\n");
                        }
                        else {
                            this->context.menu->get_player_one_button()->setText(L"AI");
                            this->context.menu->set_verif_player_one_button(false);
                            printf("Player One is AI\n");
                        }
                        return true;
                    case GUI_ID_PLAYER_TWO_BUTTON:
                        if (this->context.menu->get_verif_player_two_button() == false) {
                            this->context.menu->get_player_two_button()->setText(L"HUMAN");
                            this->context.menu->set_verif_player_two_button(true);
                            printf("Player Two is real player\n");
                        }
                        else {
                            this->context.menu->get_player_two_button()->setText(L"AI");
                            this->context.menu->set_verif_player_two_button(false);
                            printf("Player Two is AI\n");
                        }
                        return true;
                    case GUI_ID_PLAYER_THREE_BUTTON:
                        if (this->context.menu->get_verif_player_three_button() == false) {
                            this->context.menu->get_player_three_button()->setText(L"HUMAN");
                            this->context.menu->set_verif_player_three_button(true);
                            printf("Player Three is real player\n");
                        }
                        else {
                            this->context.menu->get_player_three_button()->setText(L"AI");
                            this->context.menu->set_verif_player_three_button(false);
                            printf("Player Three is AI\n");
                        }
                        return true;
                    case GUI_ID_PLAYER_FOUR_BUTTON:
                        if (this->context.menu->get_verif_player_four_button() == false) {
                            this->context.menu->get_player_four_button()->setText(L"HUMAN");
                            this->context.menu->set_verif_player_four_button(true);
                            printf("Player Four is real player\n");
                        }
                        else {
                            this->context.menu->get_player_four_button()->setText(L"AI");
                            this->context.menu->set_verif_player_four_button(false);
                            printf("Player Four is AI\n");
                        }
                        return true;
                    default:
                        return false;
                }
            default:
                break;
            }
        }
    if (event.EventType == EET_KEY_INPUT_EVENT)
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    return false;
}