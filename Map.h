//
// Created by pete on 13.06.24.
//

#ifndef DASHKING_MAP_H
#define DASHKING_MAP_H

#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Platform.h"
#include "Collectible.h"

class Map {


public:
    std::vector <Platform> platforms;
    std::vector <Collectible> collectibles;
//    std::vector <Enemies> enemies;
//    std::vector <Obstacle> obstacles;
//    int collectiblesMainVectorIndex_start;
//    int collectiblesMainVectorIndex_stop;

    bool wasShown = false;
    sf::Clock mapClock;

    Map(std::vector <Platform> tmp_platforms);

    void collect(Player & player, int i);

    std::vector<Collectible> removeCollectible(Collectible& collectible);
    std::vector<Collectible>::iterator removeCollectible(std::vector<Collectible>::iterator it);

    std::vector<Collectible> generateObjects();

    std::vector<Collectible> updateObjects();

    std::vector<Platform> getPlatforms();


};


#endif //DASHKING_MAP_H
