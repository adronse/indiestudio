/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include <iostream>
#include "core.hpp"
#include <SFML/Audio.hpp>
#include "irrlicht.h"
#include "Bomb.hpp"

class MyEventReceiver;

class Bomb;

class Game : public Thread {
    public:
        Game(std::vector<IAnimatedMeshSceneNode *>, Map *, ISceneManager *sceneManager, IVideoDriver *driver);
        ~Game();
        void set_receiver(MyEventReceiver *);
        void play_music_game();
        void stop_music_game();
        void set_verif_player_one(bool);
        void set_verif_player_two(bool);
        void run();
        bool hit_box(int, char);
        vector2di get_pos_on_map(char);
        void explosion(vector2di);
    protected:
    private:
        std::vector<std::string> kill_player(std::vector<std::string>, vector2di, int);
        int count_case(int, int);
        vector3df player_one_pos;
        vector3df player_two_pos;
        vector3df player_three_pos;
        vector3df player_four_pos;
        MyEventReceiver *receiver;
        std::vector<IAnimatedMeshSceneNode *> list_player;
        std::vector<Bomb *> list_bomb;
        sf::SoundBuffer music_game_buff;
        sf::Sound music_game;
        int verif_thread;
        bool verif_player_one;
        bool verif_player_two;
        Map *map;
        ISceneManager *sceneManager;
        IVideoDriver *driver;
};

#endif /* !GAME_HPP_ */
