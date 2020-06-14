/*
** EPITECH PROJECT, 2020
** cube
** File description:
** cube
*/

#include <core.hpp>
#include "cube.hpp"

cube::cube()
{

};

cube::~cube()
{

};

void cube::set_pos(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float cube::get_pos_x(void)
{
    return (this->x);
}

float cube::get_pos_y(void)
{
    return (this->y);
}

float cube::get_pos_z(void)
{
    return (this->z);
}

void cube::move_right(float x, float y, float z)
{
    this->x += 5;
}

void createcube(ISceneManager *sceneManager, IVideoDriver *driver, IAnimatedMeshSceneNode *wall_cube, bool verif)
{
    cube cube_one;

    cube_one.set_pos(50, 0, 0);
    wall_cube->setMaterialFlag(EMF_LIGHTING, false);
    if (verif == false)
        wall_cube->setMaterialTexture(0, driver->getTexture(GET("cube/cube.jpg")));
    else
        wall_cube->setMaterialTexture(0, driver->getTexture(GET("cube/cube_bordure.jpg")));
    // wall_cube->setMD2Animation(EMAT_STAND);    // joue l'animation STAND en boucle
    wall_cube->setScale(vector3df(0.1, 0.1, 0.1));
    wall_cube->setRotation(vector3df(0, 0, 0));
    wall_cube->setPosition(vector3df(cube_one.get_pos_x(), cube_one.get_pos_y(), cube_one.get_pos_z()));
}