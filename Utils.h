//
// Created by pete on 10.06.24.
//


#pragma once
#ifndef DASHKING_UTILS_H
#define DASHKING_UTILS_H


#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Collectible.h"
#include "Player.h"

class Utils {

    public:
        static bool resolveCollision(sf::RectangleShape& player, const sf::RectangleShape& platform, float& velocityY);
        static bool isColliding(sf::RectangleShape& player, const sf::RectangleShape& shape);
        static bool isTextClicked(const sf::Text & text, const sf::RenderWindow & window);
//    static bool isColliding(const & Player A, const & Collectible  B);
//    static bool isColliding(const  GameObject<sf::RectangleShape>& A, const  GameObject<sf::RectangleShape>& B);

};


#endif //DASHKING_UTILS_H
