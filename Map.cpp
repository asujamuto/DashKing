//
// Created by pete on 13.06.24.
//

#include "Map.h"
#include <fmt/core.h>

Map::Map(std::vector <Platform> tmp_platforms)
{
   platforms = tmp_platforms;
//   collectibles = tmp_collectibles;
   generateObjects();
}

void Map::collect(Player & player, int i)
{
        if(player.sprite.getGlobalBounds().intersects(collectibles[i] -> shape.getGlobalBounds()))
        {
//            collectibles[i].drawable = false;
            collectibles = removeCollectible(*collectibles[i]);
            player.addCoins();
        }
}

//std::vector<Collectible*>::iterator Map::removeCollectible(std::vector<Collectible>::iterator it) {
//    it = *collectibles.erase(it);
//    return it;
//}
std::vector<Collectible*> Map::generateObjects()
{
    //generate obstacles
    if(wasShown == false)
    {
        fmt::println("Uruchomiono Generate OBJ");

//        for(int i = 0; i < 2; i++)
//        {
//            spikes.push_back(
//                    Spike(4, sf::Vector2f(
//                            (shape.getPosition().x + shape.getSize().x) - ((i*30)+ 40),
//                            shape.getPosition().y - 20) )
//            );
//        }

        //coins on platform
        for(int j = 0; j < platforms.size(); j++)
        {
            if(platforms[j].name_id == "platform")
            {

                for(int i = 0; i < std::rand() % 10; i++)
                {

                    int lowerBound = platforms[j].shape.getPosition().x;
                    int higherBound = (platforms[j].shape.getPosition().x + platforms[j].shape.getSize().x);

                    collectibles.push_back(
//                        Collectible(8, sf::Vector2f((shape.getPosition().x + shape.getSize().x) - ((i*30)+ 40), shape.getPosition().y - 20), (i+1)*10)
                        new Collectible(8, sf::Vector2f(lowerBound + (std::rand() % (higherBound - lowerBound) + 1), platforms[j].shape.getPosition().y - 20), (i+1)+(10*j))
                    );
//                    collectibles[collectibles.size() -1].shape.setPosition(lowerBound + (std::rand() % (higherBound - lowerBound) + 1), 20);
                }
            }

            if(platforms[j].name_id == "enemyPlatform")
            {
                auto starting_pos = sf::Vector2f((platforms[j].shape.getPosition().x + platforms[j].shape.getSize().x)/2,
                                                  platforms[j].shape.getPosition().y - 40);
//                Enemy enemy = Enemy(sf::Vector2f(30, 40), sf::Vector2f(600, 550 - 40), 3);
                auto size = sf::Vector2f(30, 40);
                enemies.push_back(new Enemy(size, starting_pos, 3));
            }
        }
        wasShown = true;
        return collectibles;
    }
    else
    {
        return collectibles;
    }

}

std::vector<Collectible*> Map::removeCollectible(Collectible & collectible)
{
    for(int i = 0; i < collectibles.size(); i++)
    {
        if(collectibles[i]->id == collectible.id)
        {
            collectibles.erase(collectibles.begin() + i);
        }
    }

    return collectibles;
}


std::vector<Collectible*> Map::updateObjects()
{
    return collectibles;

}

std::vector<Platform> Map::getPlatforms() {
    return platforms;
}