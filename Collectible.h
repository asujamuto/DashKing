//
// Created by pete on 10.06.24.
//

//#ifndef DASHKING_COLLECTIBLE_H
//#define DASHKING_COLLECTIBLE_H
#pragma once
#include "GameObject.h"
#include "Player.h"

class Collectible : public GameObject<sf::CircleShape>
{

    public:
        int id;
        bool collected = false;
        bool drawable = true;

        Collectible(float radius, sf::Vector2f position, int n) : GameObject<sf::CircleShape>(radius, position)
        {
            id = n;
            shape.setFillColor(sf::Color::Yellow);
        }


//        auto hide()
//        {
//            if(collected == true)
//            {
//
//            }
//        }

};


//#endif //DASHKING_COLLECTIBLE_H
