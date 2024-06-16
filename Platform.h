//
// Created by pete on 10.06.24.
//

#ifndef DASHKING_PLATFORM_H
#define DASHKING_PLATFORM_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Collectible.h"
#include "Spike.h"

class Platform : public GameObject<sf::RectangleShape> {

    public:
        std::string name_id;
//        std::vector<Collectible> collectibles;
        std::vector<Spike> spikes;
        bool wasShown = false;
        bool drawable = true;

        Platform(sf::Vector2f size = sf::Vector2f(500, 30), sf::Vector2f position = sf::Vector2f(0, 0), std::string name = "defualt");


        sf::RectangleShape operator ()()
        {
            return shape;
        }

//        std::vector<Collectible> removeCollectible(Collectible& collectible);
//        std::vector<Collectible> generateObjects();

//        std::vector<Collectible> updateObjects();




};


#endif //DASHKING_PLATFORM_H
