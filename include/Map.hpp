/*
** EPITECH PROJECT, 2020
** Map
** File description:
** Map
*/

#ifndef Map_h
#define Map_h

#include <iostream>
#include <vector>
#include "irrlicht.h"
#include "core.hpp"
#include "cube.hpp"

class Map {
    public:
        Map(ISceneManager *, IVideoDriver *);
        ~Map();
        void set_map(std::vector<std::string>);
        std::vector<std::string> get_map();
        void set_case();
        void destroy_case(int);
    private:
        std::vector<std::string> map;
        std::vector<IAnimatedMeshSceneNode *> list_cube;
        std::vector<IAnimatedMeshSceneNode *> list_wall;
        ISceneManager *sceneManager;
        IVideoDriver *driver;
};

#endif /* !Map_h */
