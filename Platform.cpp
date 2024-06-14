//
// Created by pete on 10.06.24.
//

#include "Platform.h"
#include <algorithm>

Platform::Platform(sf::Vector2f size, sf::Vector2f position, const std::string name)
: GameObject(size, position)
{
    name_id = name;
    collectibles = generateObjects();

}

std::vector<Collectible> Platform::generateObjects()
{
    //generate obstacles
    if(wasShown == false)
    {

    for(int i = 0; i < 2; i++)
    {
        spikes.push_back(
                Spike(4, sf::Vector2f(
                        (shape.getPosition().x + shape.getSize().x) - ((i*30)+ 40),
                        shape.getPosition().y - 20) )
        );
    }
    //coins on platform
    for(int i = 0; i < 6; i++)
    {
        collectibles.push_back(
                Collectible(8, sf::Vector2f((shape.getPosition().x + shape.getSize().x) - ((i*30)+ 40), shape.getPosition().y - 20), (i+1)*10)
        );
    }

        wasShown = true;
        return collectibles;
    }
    else
    {
       return collectibles;
    }

}

std::vector<Collectible> Platform::removeCollectible(Collectible& collectible)
{
//    auto it = std::find(collectibles.begin(), collectibles.end(), collectible.id);
    for(int i = 0; i  < collectibles.size(); i++)
    {
        if(collectible.id == collectibles[i].id)
        {
            collectibles.erase(collectibles.begin() + i);
        }
    }
//    collectibles.erase(std::remove(collectibles.begin(), collectibles.end(), collectible), collectibles.end());

    return collectibles;
}


std::vector<Collectible> Platform::updateObjects()
{
    return collectibles;

}
