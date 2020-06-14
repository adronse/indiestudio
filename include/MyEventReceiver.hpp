/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MyEventReceiver
*/

#ifndef MYEVENTRECEIVER_HPP_
#define MYEVENTRECEIVER_HPP_

#include "Game.hpp"
#include "core.hpp"
#include "menu.hpp"
#include "Map.hpp"

class Game;

struct SAppContext
{
    IrrlichtDevice *device;
    s32             counter;
    IGUIListBox*    listbox;
    Menu *menu;
    Game *game;
    Map *map;
    E_DRIVER_TYPE driverType;
    Core *core;
};

enum
{
    GUI_ID_QUIT_BUTTON = 101,
    GUI_ID_PLAY_BUTTON,
    GUI_ID_SETTINGS_BUTTON,
    GUI_ID_FULL_SCREEN_BUTTON,
    GUI_ID_WINDOW_1080_BUTTON,
    GUI_ID_WINDOW_480_BUTTON,
    GUI_ID_BACK_MENU_BUTTON,
    GUI_ID_START_BUTTON,
    GUI_ID_PLAYER_ONE_BUTTON,
    GUI_ID_PLAYER_TWO_BUTTON,
    GUI_ID_PLAYER_THREE_BUTTON,
    GUI_ID_PLAYER_FOUR_BUTTON,
    GUI_ID_KEY_A

};

class MyEventReceiver : public IEventReceiver
{
    public:
        MyEventReceiver(SAppContext & context) : context(context) {
            for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
            KeyIsDown[i] = false;
        }
        ~MyEventReceiver() = default;
        virtual bool OnEvent(const SEvent& event);
        virtual bool IsKeyDown(EKEY_CODE keyCode) const {
            return KeyIsDown[keyCode];
        }
    private:
        bool KeyIsDown[KEY_KEY_CODES_COUNT];
        SAppContext &context;
};

#endif /* !MYEVENTRECEIVER_HPP_ */
