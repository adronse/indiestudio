/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Game
*/

#include "Game.hpp"
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

Game::Game(std::vector<IAnimatedMeshSceneNode *> list_player, Map *map, ISceneManager *sceneManager, IVideoDriver *driver)
{
    this->sceneManager = sceneManager;
    this->driver = driver;
    this->map = map;
    this->list_player = list_player;
    this->player_one_pos = vector3df(255, -33, 25);
    this->player_two_pos = vector3df(255 - (16 * 13), -33, 25);
    this->player_three_pos = vector3df(255, -33, 25 + (16 * (17 - 3)));
    this->player_four_pos = vector3df(255 - (16 * 13), -33, 25 + (16 * (17 - 3)));
    this->verif_thread = 0;
}

Game::~Game()
{

}

void Game::set_receiver(MyEventReceiver *receiver)
{
    this->receiver = receiver;
}

void Game::set_verif_player_one(bool verif_player_one)
{
    this->verif_player_one = verif_player_one;
}

void Game::set_verif_player_two(bool verif_player_two)
{
    this->verif_player_two = verif_player_two;
}

void Game::run()
{
    if (this->verif_thread == 1) {
        while (true) {
            usleep(50000);
            if (this->receiver->IsKeyDown(KEY_KEY_I)) {
                printf("i key is down\n");
                if (this->hit_box(0, '2') == true) {
                    this->player_two_pos -= vector3df(0, 0, 10);
                    this->list_player[1]->setPosition(this->player_two_pos);
                }
            }
            if (this->receiver->IsKeyDown(KEY_KEY_K)) {
                printf("k key is down\n");
                if (this->hit_box(1, '2') == true) {
                    this->player_two_pos += vector3df(0, 0, 10);
                    this->list_player[1]->setPosition(this->player_two_pos);
                }
            }
            if (this->receiver->IsKeyDown(KEY_KEY_L)) {
                printf("l key is down\n");
                if (this->hit_box(2, '2') == true) {
                    this->player_two_pos -= vector3df(10, 0, 0);
                    this->list_player[1]->setPosition(this->player_two_pos);
                }
            }
            if (this->receiver->IsKeyDown(KEY_KEY_J)) {
                printf("j key is down\n");
                if (this->hit_box(3, '2') == true) {
                    this->player_two_pos += vector3df(10, 0, 0);
                    this->list_player[1]->setPosition(this->player_two_pos);
                }
            }
        }
    }
    if (this->verif_player_two == true) {
        this->verif_thread = 1;
        this->launchThread();
    }
    while (this->verif_player_one == true) {
        usleep(50000);
        if (this->receiver->IsKeyDown(KEY_KEY_Z)) {
            printf("z key is down\n");
            if (this->hit_box(0, '1') == true) {
                this->player_one_pos -= vector3df(0, 0, 10);
                this->list_player[0]->setPosition(this->player_one_pos);
            }
        }
        if (this->receiver->IsKeyDown(KEY_KEY_S)) {
            printf("s key is down\n");
            if (this->hit_box(1, '1') == true) {
                this->player_one_pos += vector3df(0, 0, 10);
                this->list_player[0]->setPosition(this->player_one_pos);
            }
        }
        if (this->receiver->IsKeyDown(KEY_KEY_D)) {
            printf("d key is down\n");
            if (this->hit_box(2, '1') == true) {
                this->player_one_pos -= vector3df(10, 0, 0);
                this->list_player[0]->setPosition(this->player_one_pos);
            }
        }
        if (this->receiver->IsKeyDown(KEY_KEY_Q)) {
            printf("q key is down\n");
            if (this->hit_box(3, '1') == true) {
                this->player_one_pos += vector3df(10, 0, 0);
                this->list_player[0]->setPosition(this->player_one_pos);
            }
        }
        if (this->receiver->IsKeyDown(KEY_SPACE)) {
            printf("space key is down\n");
            if (this->list_bomb.size() != 0) {
                if (this->list_bomb.back()->get_verif() == true)
                    continue;
            }
            this->list_bomb.push_back(new Bomb(this->sceneManager, this->driver, this->get_pos_on_map('1'), this->player_one_pos, this));
            this->list_bomb.back()->launchThread();
        }
    }
}

void Game::play_music_game()
{
    if (!this->music_game_buff.loadFromFile(GET("game_music.ogg")))
        exit(84);
    this->music_game.setBuffer(this->music_game_buff);
    this->music_game.play();
}

void Game::stop_music_game()
{
    this->music_game.stop();
}

vector2di Game::get_pos_on_map(char player)
{
    std::vector<std::string> map = this->map->get_map();

    for (int i = 0; i != map.size(); i++) {
        for (int y = 0; map[i][y]; y++) {
            if (map[i][y] == player) {
                return vector2di(i, y);
            }
        }
    }
    return vector2di(0, 0);
}

void Game::explosion(vector2di pos)
{
    std::vector<std::string> map = this->map->get_map();

    if (map[pos.X][pos.Y - 1] == 'O') {
        this->map->destroy_case(this->count_case(pos.X, pos.Y - 1));
        map[pos.X][pos.Y - 1] = ' ';
    }
    if (map[pos.X][pos.Y + 1] == 'O') {
        this->map->destroy_case(this->count_case(pos.X, pos.Y + 1));
        map[pos.X][pos.Y + 1] = ' ';
    }
    if (map[pos.X - 1][pos.Y] == 'O') {
        this->map->destroy_case(this->count_case(pos.X - 1, pos.Y));
        map[pos.X - 1][pos.Y] = ' ';
    }
    if (map[pos.X + 1][pos.Y] == 'O') {
        this->map->destroy_case(this->count_case(pos.X + 1, pos.Y));
        map[pos.X + 1][pos.Y] = ' ';
    }
    for (int i = 0; i != 4; i++)
        map = this->kill_player(map, pos, i);
    this->map->set_map(map);
}

int Game::count_case(int y, int x)
{
    std::vector<std::string> map = this->map->get_map();
    int count = 0;

    for (int i = 0; i != y + 1; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (i == y && j == x)
                return count;
            if (map[i][j] == 'O')
                count++;
        }
    }
    return count;
}

std::vector<std::string> Game::kill_player(std::vector<std::string> map, vector2di pos, int player_int)
{
    if (map[pos.X][pos.Y - 1] == (char)player_int + 1) {
        map[pos.X][pos.Y - 1] = ' ';
        this->list_player[player_int]->remove();
    }
    if (map[pos.X][pos.Y + 1] == (char)player_int + 1) {
        map[pos.X][pos.Y + 1] = ' ';
        this->list_player[player_int]->remove();
    }
    if (map[pos.X - 1][pos.Y] == (char)player_int + 1) {
        map[pos.X - 1][pos.Y] = ' ';
        this->list_player[player_int]->remove();
    }
    if (map[pos.X + 1][pos.Y] == (char)player_int + 1) {
        map[pos.X + 1][pos.Y] = ' ';
        this->list_player[player_int]->remove();
    }
    return map;
}

bool Game::hit_box(int direction, char player)
{
    std::vector<std::string> map = this->map->get_map();

    for (int i = 0; i != map.size(); i++) {
        for (int y = 0; map[i][y]; y++) {
            if (map[i][y] == player && direction == 0 && map[i - 1][y] == ' ' && i - 1 > 0) {
                map[i][y] = ' ';
                map[i - 1][y] = player;
                this->map->set_map(map);
                return true;
            }
            else if (map[i][y] == player && direction == 1 && map[i + 1][y] == ' ' && i + 1 < 16) {
                map[i][y] = ' ';
                map[i + 1][y] = player;
                this->map->set_map(map);
                return true;
            }
            else if (map[i][y] == player && direction == 2 && map[i][y + 1] == ' ' && y + 1 < 16) {
                map[i][y] = ' ';
                map[i][y + 1] = player;
                this->map->set_map(map);
                return true;
            }
            else if (map[i][y] == player && direction == 3 && map[i][y - 1] == ' ' && y - 1 > 0) {
                map[i][y] = ' ';
                map[i][y - 1] = player;
                this->map->set_map(map);
                return true;
            }
        }
    }
    return false;
}