/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "Thread.hpp"
#include "irrlicht.h"
#include "core.hpp"

class Game;

class Bomb : public Thread {
    public:
        Bomb(ISceneManager *, IVideoDriver *,vector2di , vector3df, Game *);
        ~Bomb();
        void run();
        bool get_verif();
    protected:
    private:
        IAnimatedMeshSceneNode *bomb;
        vector2di pos_map;
        vector3df position_3d;
        bool verif;
        Game *game;
};

#endif /* !BOMB_HPP_ */
