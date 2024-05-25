//
// Created by pete on 23.05.24.
//


#include "PlayerInterface.h"

PlayerInterface::PlayerInterface(){
    auto heart = GameObject(sf::Vector2f(130,113), sf::Vector2f(0,0), "heart.png");

    hearts = std::vector<GameObject>{
            heart, heart, heart
    };

    int gapSize = 0;
    for(auto heart : hearts)
    {
        heart.setPosition(sf::Vector2f(20, 20 + gapSize));
        gapSize += 20;
    }
}