/*
** EPITECH PROJECT, 2020
** cube
** File description:
** cube
*/

#ifndef cube_hpp
#define cube_hpp


#include <iostream>
#include "irrlicht.h"
#include "error.hpp"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class cube {
    private:
        float x;
        float y;
        float z;
    public:
        cube();
        ~cube();
        void set_pos(float, float, float);
        float get_pos_x();
        float get_pos_y();
        float get_pos_z();
        void move_right(float x, float y, float z);
};

void createcube(ISceneManager *sceneManager, IVideoDriver *driver, IAnimatedMeshSceneNode *cube, bool);

#endif /* !cube_hpp */
