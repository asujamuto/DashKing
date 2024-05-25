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

    std::vector<GameObject> hearts;
    PlayerInterface();

};


#endif //UNTITLED_PLAYERINTERFACE_H
