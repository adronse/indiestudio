/*
** EPITECH PROJECT, 2020
** core
** File description:
** core
*/

#include <iostream>
#include <vector>
#include "irrlicht.h"
#include "driverChoice.h"
#include "error.hpp"
#include "player.hpp"
#include "MyEventReceiver.hpp"
#include "Game.hpp"
#include "Map.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifndef core_h
#define core_h
    #ifndef ASSETS
        #define ASSETS "./assets/"
    #endif
#define GET(x) std::string(ASSETS).append(x).c_str()

class Map;

class Core
{
    public:
        Core(IrrlichtDevice *, E_DRIVER_TYPE);
        ~Core();
        void setDevice(IrrlichtDevice *);
        void loop();
    protected:
    private:
        std::vector<IAnimatedMeshSceneNode *> list_player;
        E_DRIVER_TYPE driverType;
        IrrlichtDevice *device;
        IVideoDriver *driver;
        ISceneManager *sceneManager;
        ITexture *menu_texture;
};

#endif /* !core_h */