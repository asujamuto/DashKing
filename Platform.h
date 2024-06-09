//
// Created by pete on 26.05.24.
//

#pragma once
#include "GameObject.h"
#include "Player.h"

struct Platform : public GameObject {

    bool is_collising;
    bool current_platform;

    Platform(sf::Vector2f textureSize,
             sf::Window const& window,
             std::string textureName,
             bool colide
             );


    int resolveCollision(GameObject& p);

    ~Platform() override
    {
        delete this;
    }

};


