/*
** EPITECH PROJECT, 2020
** Map
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(ISceneManager *sceneManager, IVideoDriver *driver)
{
    this->sceneManager = sceneManager;
    this->driver = driver;
    this->map.push_back("XXXXXXXXXXXXXXXX");
    this->map.push_back("X1 OOOOOOOOOO 2X");
    this->map.push_back("X XXOXOXOXOXOX X");
    this->map.push_back("XXOOXXOXXOXXOOXX");
    this->map.push_back("XXOOXXOXXOXOOOXX");
    this->map.push_back("XXXOOOOOOOXOXOOX");
    this->map.push_back("XXOOOOOXOOXOXOXX");
    this->map.push_back("XXOOXOOOOOXOXOOX");
    this->map.push_back("XOOOOOOOOOOOOOOX");
    this->map.push_back("XXOOXOOOOOXOXOOX");
    this->map.push_back("XXOOOOOXOOXOXOXX");
    this->map.push_back("XXXOOOOOOOXOXOOX");
    this->map.push_back("XXOOXXOXXOXOOOXX");
    this->map.push_back("XXOOXXOXXOXXOOXX");
    this->map.push_back("X XXOXOXOXOXOX X");
    this->map.push_back("X3 OOOOOOOOOO 4X");
    this->map.push_back("XXXXXXXXXXXXXXXX");
    printf("String Map create\n");
}

Map::~Map()
{

}

void Map::set_map(std::vector<std::string> map)
{
    this->map = map;
}

std::vector<std::string> Map::get_map()
{
    return this->map;
}

void Map::set_case()
{
    for (int i = 0; i != this->map.size(); i++) {
        for (int y = 0; this->map[i][y]; y++) {
            if (this->map[i][y] == 'X') {
                this->list_wall.push_back(this->sceneManager->addAnimatedMeshSceneNode(this->sceneManager->getMesh(GET("cube/cube.obj"))));
                createcube(this->sceneManager, this->driver, this->list_wall.back(), true);
                this->list_wall.back()->setPosition(vector3df(270 - (16 * y), -25, 10 + (16 * i)));
            }
            else if (this->map[i][y] == 'O') {
                this->list_cube.push_back(this->sceneManager->addAnimatedMeshSceneNode(this->sceneManager->getMesh(GET("cube/cube.obj"))));
                createcube(this->sceneManager, this->driver, this->list_cube.back(), false);
                this->list_cube.back()->setPosition(vector3df(270 - (16 * y), -32, 10 + (16 * i)));
            }
        }
        std::cout << "case line " << i << " set on Map: " << this->map[i] << std::endl;
    }
}

void Map::destroy_case(int i)
{
    std::cout << "TON PERE" << std::endl;
    this->list_cube[i]->setPosition(vector3df(-500, -500, -500));
    this->list_cube.erase(this->list_cube.begin() + i);
}