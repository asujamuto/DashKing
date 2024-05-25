//
// Created by pete on 06.05.24.
//

#pragma once
#ifndef UNTITLED_SCENE_H
#define UNTITLED_SCENE_H

#include "Player.h"
#include <vector>

struct Scene {

    std::vector <GameObject> renderSprites;

    Scene(GameObject background, GameObject floor, Player player, sf::Vector2f windowCords);
};


#endif //UNTITLED_SCENE_H
