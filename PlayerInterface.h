//
// Created by pete on 23.05.24.
//

#pragma once
#ifndef UNTITLED_PLAYERINTERFACE_H
#define UNTITLED_PLAYERINTERFACE_H

#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include <vector>

struct PlayerInterface{
    //INITIALIZE HEARTS

    std::vector<GameObject*> hearts = {
            new GameObject(sf::Vector2f(130,113), sf::Vector2f(0,0), "assets/playerInterface/heart.png"),
            new GameObject(sf::Vector2f(130,113), sf::Vector2f(0,0), "assets/playerInterface/heart.png"),
            new GameObject(sf::Vector2f(130,113), sf::Vector2f(0,0), "assets/playerInterface/heart.png")
    };

    PlayerInterface(sf::Window const& main_window);
    ~PlayerInterface();

};


#endif //UNTITLED_PLAYERINTERFACE_H
