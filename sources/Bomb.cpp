/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include <unistd.h>

Bomb::Bomb(ISceneManager *sceneManager, IVideoDriver *driver, vector2di pos_map, vector3df position_3d, Game *game)
{
    this->game = game;
    this->pos_map = pos_map;
    this->position_3d = position_3d;
    this->bomb = sceneManager->addAnimatedMeshSceneNode(sceneManager->getMesh(GET("bomb/bomb.3ds")));
    this->bomb->setPosition(this->position_3d);
    this->bomb->setMaterialFlag(EMF_LIGHTING, false);
    this->bomb->setMaterialTexture(0, driver->getTexture(GET("bomb/bomb.png")));
    this->bomb->setScale(vector3df(1.5, 1.5, 1.5));
    this->verif = true;
}

Bomb::~Bomb()
{

}

bool Bomb::get_verif()
{
    return this->verif;
}

void Bomb::run()
{
    sleep(2);
    this->verif = false;
    printf("BOM!\n");
    this->game->explosion(this->pos_map);
    this->bomb->setPosition(vector3df(-500, -500, -500));
}