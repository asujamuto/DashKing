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






        MapsConnector(sf::RenderWindow& main_window)
        {
            window = std::unique_ptr<sf::RenderWindow>(&main_window);
            clock = sf::Clock();
        };

        void updatePlatform(Player & player);

        Map updateMap(Player & player);

        Map change(int map);
//        void generateMaps();


//        std::vector<Platform>& map_swap(Player & player);

//        std::vector<Platform> import(std::string file);

        virtual ~MapsConnector()
        {
            window.release();
            delete this;
        }
};




#endif //DASHKING_MAPSCONNECTOR_H
