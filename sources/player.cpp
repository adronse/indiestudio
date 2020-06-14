/*
** EPITECH PROJECT, 2020
** player.cpp
** File description:
** player
*/

#include <core.hpp>
#include "player.hpp"

player::player()
{

};

player::~player()
{

};

void player::set_pos(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float player::get_pos_x(void)
{
    return (this->x);
}

float player::get_pos_y(void)
{
    return (this->y);
}

float player::get_pos_z(void)
{
    return (this->z);
}

void player::move_right(float x, float y, float z)
{
    this->x += 5;
}

void createplayer(ISceneManager *sceneManager, IVideoDriver *driver, IAnimatedMeshSceneNode *ironman)
{
    player player_one;

    player_one.set_pos(255, -33, 25);
    ironman->setMaterialFlag(EMF_LIGHTING, false);
    ironman->setMaterialTexture(0, driver->getTexture(GET("bomberman/Blue_perso.png")));
    // ironman->setMD2Animation(EMAT_STAND);    // joue l'animation STAND en boucle
    ironman->setScale(vector3df(2, 2, 2));
    ironman->setRotation(vector3df(0, -100, 0));
    ironman->setPosition(vector3df(player_one.get_pos_x(), player_one.get_pos_y(), player_one.get_pos_z()));
}

void player::run()
{

}