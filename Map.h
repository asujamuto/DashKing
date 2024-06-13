//
// Created by pete on 10.06.24.
//

#pragma once

#ifndef DASHKING_MAP_H
#define DASHKING_MAP_H
#include <vector>

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <memory>
#include "Platform.h"
#include "Player.h"
#include <fstream>


class Map {

    public:
        std::unique_ptr<sf::RenderWindow> window = nullptr;
        std::vector<Platform> platforms;
        std::vector< std::vector<Platform> > maps;


        int current_map = 0;
        sf::Clock clock;


        Map(sf::RenderWindow& main_window)
        {
            window = std::unique_ptr<sf::RenderWindow>(&main_window);
            clock = sf::Clock();
        };

        void update(Platform& plat, Player & player);

        std::vector<Platform> change(int map);
        std::vector<std::vector<Platform>> generateMaps();


//        std::vector<Platform>& map_swap(Player & player);

//        std::vector<Platform> import(std::string file);

        ~Map()
        {
            delete this;
        }
};




#endif //DASHKING_MAP_H
