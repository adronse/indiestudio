/*
** EPITECH PROJECT, 2020
** loop
** File description:
** loop
*/

#include "core.hpp"
#include "menu.hpp"
#include "MyEventReceiver.hpp"
#include "player.hpp"
#include "cube.hpp"

void cam(ISceneManager *sceneManager)
{
    SKeyMap keyMap[5];                    // re-assigne les commandes
    keyMap[0].Action = EKA_MOVE_FORWARD;  // avancer
    keyMap[0].KeyCode = KEY_KEY_Z;        // w
    keyMap[1].Action = EKA_MOVE_BACKWARD; // reculer
    keyMap[1].KeyCode = KEY_KEY_S;        // s
    keyMap[2].Action = EKA_STRAFE_LEFT;   // a gauche
    keyMap[2].KeyCode = KEY_KEY_Q;        // a
    keyMap[3].Action = EKA_STRAFE_RIGHT;  // a droite
    keyMap[3].KeyCode = KEY_KEY_D;        // d
    keyMap[4].Action = EKA_JUMP_UP;       // saut
    keyMap[4].KeyCode = KEY_SPACE;        // barre espace
    keyMap[5].KeyCode =  KEY_ESCAPE;
    //keyMap[5].Action = exit(0);
    sceneManager->addCameraSceneNode(0, core::vector3df(140, 195, 150), core::vector3df(140, 0, 143), true);

    /*sceneManager->addCameraSceneNodeFPS(                // ajout de la camera FPS
    0, 100.0f, 0.1f, -1, keyMap, 5);*/
}

Core::Core(IrrlichtDevice *device, E_DRIVER_TYPE driverType)
{
    this->driverType = driverType;
    this->device = device;
    this->device->setWindowCaption(L"Indie Studio: Bomberman !"); // Y CRASH ICI LE FILS DE PUTE
    this->driver = this->device->getVideoDriver();
    this->sceneManager = this->device->getSceneManager();

    for (int i = 0; i != 4; i++) {
        this->list_player.push_back(this->sceneManager->addAnimatedMeshSceneNode(this->sceneManager->getMesh(GET("bomberman/Bomberman.b3d"))));
        this->list_player[i]->setFrameLoop(0, 13);
        this->list_player[i]->setAnimationSpeed(7);
        createplayer(this->sceneManager, this->driver, this->list_player[i]);
    }
    this->list_player[0]->setRotation(vector3df(0, 100, 0));
    this->list_player[1]->setPosition(vector3df(255 - (16 * 13), -33, 25));
    this->list_player[2]->setPosition(vector3df(255, -33, 25 + (16 * (17 - 3))));
    this->list_player[2]->setRotation(vector3df(0, 100, 0));
    this->list_player[3]->setPosition(vector3df(255 - (16 * 13), -33, 25 + (16 * (17 - 3))));

    cam(this->sceneManager);
}

Core::~Core()
{

}

void Core::setDevice(IrrlichtDevice *device)
{
    this->device = device;
    this->driver = this->device->getVideoDriver();
    printf("set new device\n");

    this->sceneManager = this->device->getSceneManager();

    this->list_player.push_back(this->sceneManager->addAnimatedMeshSceneNode(this->sceneManager->getMesh(GET("bomberman/Bomberman.b3d"))));
    this->list_player[0]->setFrameLoop(0, 13);
    this->list_player[0]->setAnimationSpeed(7);
    createplayer(this->sceneManager, this->driver, this->list_player[0]);
    cam(this->sceneManager);
}

void Core::loop()
{
    Menu *menu = new Menu;
    Map *map = new Map(this->sceneManager, this->driver);
    Game *game = new Game(this->list_player, map, this->sceneManager, this->driver);
    menu->set_Menu(this->sceneManager);
    IGUIListBox *listbox = this->device->getGUIEnvironment()->addListBox(rect<s32>(-50, -140, -250, -210));
    SAppContext context;
    context.device = this->device;
    context.counter = 0;
    context.listbox = listbox;
    context.menu = menu;
    context.game = game;
    context.map = map;
    context.core = this;
    context.driverType = this->driverType;
    MyEventReceiver receiver(context);
    this->device->setEventReceiver(&receiver);
    game->set_receiver(&receiver);

    SColor color(255, 255, 255, 255);
    // int lastFPS = -1;
    // u32 then = this->device->getTimer()->getTime();
    // const f32 MOVEMENT_SPEED = 5.f;

    while (this->device->run()) {
        // const u32 now = this->device->getTimer()->getTime();
        // const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
        // then = now;
        if (this->device->isWindowActive()) {
            this->device->getVideoDriver()->beginScene(true, true, color);
            if (menu->get_verif() == true) {
                menu->draw_menu();
                if (menu->get_select_menu_verif() == true) {
                    menu->get_player_one_font()->draw(L"Player One", rect<irr::s32>(335, 390, 625, 440), video::SColor(255,255,255,255));
                    menu->get_player_two_font()->draw(L"Player Two", rect<irr::s32>(735, 390, 1025, 440), video::SColor(255,255,255,255));
                    menu->get_player_three_font()->draw(L"Player Three", rect<irr::s32>(1135, 390, 1425, 440), video::SColor(255,255,255,255));
                    menu->get_player_four_font()->draw(L"Player Four", rect<irr::s32>(1535, 390, 1825, 440), video::SColor(255,255,255,255));
                }
            }
            else {
                this->sceneManager->drawAll();
            }
            this->device->getVideoDriver()->endScene();
        }
    }
    printf("LEAVE LOOP");
}