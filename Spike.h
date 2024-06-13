//
// Created by pete on 12.06.24.
//

#ifndef DASHKING_SPIKE_H
#define DASHKING_SPIKE_H

#pragma once
#include "GameObject.h"

class Spike : GameObject<sf::CircleShape> {


    public:
        int damage = 3;



   Spike(float size, sf::Vector2f position) : GameObject<sf::CircleShape>(size, position, 3){};

};


#endif //DASHKING_SPIKE_H
