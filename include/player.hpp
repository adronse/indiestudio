/*
** EPITECH PROJECT, 2020
** player
** File description:
** player
*/

#include <iostream>
#include "irrlicht.h"
#include "error.hpp"
#include "Thread.hpp"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifndef player_h
#define player_h

class player : public Thread {
    private:
        float x;
        float y;
        float z;
    public:
        player();
        ~player();
        void set_pos(float, float, float);
        float get_pos_x();
        float get_pos_y();
        float get_pos_z();
        void move_right(float x, float y, float z);
        void run();
};

void createplayer(ISceneManager *sceneManager, IVideoDriver *driver, IAnimatedMeshSceneNode *ironman);

#endif /* !player_h */
