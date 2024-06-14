//
// Created by pete on 10.06.24.
//

#pragma once

#ifndef DASHKING_MAPSCONNECTOR_H
#define DASHKING_MAPSCONNECTOR_H
#include <vector>

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <memory>
#include "Platform.h"
#include "Player.h"
#include <fstream>
#include "Map.h"


class MapsConnector {

    public:
        std::unique_ptr<sf::RenderWindow> window = nullptr;
//        std::vector<Platform> platforms;


        std::vector<Map> maps;



        int current_map = 0;
        sf::Clock clock;

        std::vector<bool> isMapShowed = {
                false,
                false,
                false,
                false,
        };






        explicit MapsConnector(sf::RenderWindow& main_window)
        {
            window = std::unique_ptr<sf::RenderWindow>(&main_window);
            clock = sf::Clock();
        };

        void update(Platform& plat, Player & player);

        std::vector<Platform> change(int map);
        void generateMaps();


//        std::vector<Platform>& map_swap(Player & player);

//        std::vector<Platform> import(std::string file);

        ~MapsConnector()
        {
            delete this;
        }
};




#endif //DASHKING_MAPSCONNECTOR_H
