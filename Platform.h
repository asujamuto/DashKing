//
// Created by pete on 26.05.24.
//

#ifndef DASHKING_PLATFORM_H
#define DASHKING_PLATFORM_H

#include "GameObject.h"
#include "Player.h"

struct Platform : public GameObject {

    bool is_collising;

    Platform(sf::Vector2f textureSize,
             sf::Window const& window,
             std::string textureName,
             bool colide
             );

    void collision(Player* p);

};


#endif //DASHKING_PLATFORM_H
