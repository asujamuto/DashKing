//
// Created by pete on 13.06.24.
//

#include "Map.h"


Map::Map(std::vector <Platform> tmp_platforms)
{
   platforms = tmp_platforms;
//   collectibles = tmp_collectibles;
   generateObjects();
}

//void Map::collect(Player & player, int index)
//{
//    if(player.sprite.getGlobalBounds().intersects(collectibles[index].shape.getGlobalBounds()))
//    {
//        collectibles.erase(collectibles.begin() + index, collectibles.end() + index);
//        player.addCoins();
//    }
//}

std::vector<Collectible> Map::generateObjects()
{
    //generate obstacles
    if(wasShown == false)
    {

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
                        Collectible(8, sf::Vector2f(lowerBound + (std::rand() % (higherBound - lowerBound) + 1), platforms[j].shape.getPosition().y - 20), (i+1)+(10*j))
                    );

//                    collectibles[collectibles.size() -1].shape.setPosition(lowerBound + (std::rand() % (higherBound - lowerBound) + 1), 20);
                }
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

std::vector<Collectible> Map::removeCollectible(Collectible& collectible)
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


std::vector<Collectible> Map::updateObjects()
{
    return collectibles;

}

std::vector<Platform> Map::getPlatforms() {
    return platforms;
}