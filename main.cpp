#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Player.h"
#include "MapsConnector.h"
#include <fmt/core.h>
#include "Enemy.h"

// Constants



// Main function
int main()
{
    Player player = Player();
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dash King");
    // Set the frame rate limit
    window.setFramerateLimit(60);


    MapsConnector mapConnector = MapsConnector(window);

    std::vector<Platform> map0 = {
            Platform(sf::Vector2f(window.getSize().x, window.getSize().y), sf::Vector2f(0, 550), "platform")
    };
    std::vector<Platform> map1 = {

            Platform(sf::Vector2f(200, window.getSize().y), sf::Vector2f(0, 550), "platform"),
            Platform(sf::Vector2f(200, window.getSize().y), sf::Vector2f(200,400), "platform1"),
            Platform(sf::Vector2f(200, window.getSize().y), sf::Vector2f(400,300), "platform"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 500), "platform"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, 640), "lift"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 900), "platform"),
            Platform(sf::Vector2f(500, 60), sf::Vector2f(window.getSize().x - 200, window.getSize().y - 240), "platform"),


    };
    std::vector map2 = {
            Platform(sf::Vector2f(500, 30), sf::Vector2f(-50, window.getSize().y - 240), "platform"),
            Platform(sf::Vector2f(200, 20), sf::Vector2f(250,200), "platform"),
            Platform(sf::Vector2f(200, 20), sf::Vector2f(550,500), "lift"),
            Platform(sf::Vector2f(500, 20), sf::Vector2f(650, 920), "platform"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, window.getSize().y - 400), "lift"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(1920 - 200, window.getSize().y - 700), "platform"),
    };

    std::vector map3 = {
            Platform(sf::Vector2f(500, 30), sf::Vector2f(-20, window.getSize().y - 700), "platform"),
            Platform(sf::Vector2f(200, 30), sf::Vector2f(450,900), "platform1"),
            Platform(sf::Vector2f(200, 30), sf::Vector2f(650,900), "platform"),
            Platform(sf::Vector2f(500, 30), sf::Vector2f(450, 750), "platform"),
            Platform(sf::Vector2f(200, 30), sf::Vector2f(1000, 720), "lift"),
            Platform(sf::Vector2f(500, 30), sf::Vector2f(1200, 200), "platform"),

    };

    //push back KOPIUJE obiek, a emplace_back dodaje go bezpośrednio do vectora
    mapConnector.maps.emplace_back(map0);
    mapConnector.maps.emplace_back(map1);
    mapConnector.maps.emplace_back(map2);
    mapConnector.maps.emplace_back(map3);
    auto map = mapConnector.maps[mapConnector.current_map];

//    auto maps = map1.generateMaps();
    std::vector<Collectible> collectibles;
    std::vector<sf::RectangleShape> hearts = player.Interface(window);
    Enemy enemy = Enemy(sf::Vector2f(30, 40), sf::Vector2f(600, 550 - 40), 3);



    // Clock for timing
    sf::Clock clock;

//    for(auto & plat : platforms)
//    {
//        if(plat.name_id == "platform")
//        {
//            collectibles = plat.generateObjects();
//        }
//
//    }




    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || player.getHearts() <= 0 )
            {
                window.close();
            }
        }

        // Clear the screen
        window.clear();

        player.movement(clock, map.platforms);


        for(auto & heart : hearts)
        {
            window.draw(heart);
        }

        //draw special platforms
        for(auto & plat : map.getPlatforms())
        {
            mapConnector.update(plat, player);
        }

        // Draw the player
        window.draw(player.sprite);

        // Draw the platforms
        for (auto& platform : map.getPlatforms())
        {
            window.draw(platform.shape);

            // Manage collectibles
            for(int i = 0; i < platform.collectibles.size(); i++)
            {
                window.draw(platform.collectibles[i].shape);
                if(player.sprite.getGlobalBounds().intersects(platform.collectibles[i].shape.getGlobalBounds()))
                {
                    platform.removeCollectible(platform.collectibles[i]);
                    player.addCoins();
                    fmt::println("touching {}", i);
                }


            }



        }



        if(player.sprite.getPosition().x > window.getSize().x )
        {
//            platforms = map1.change(map1.current_map + 1);
            map = mapConnector.maps[mapConnector.current_map + 1];
            mapConnector.current_map++;

            for(auto & plat : map.getPlatforms())
            {
                if(plat.name_id == "platform")
                {
                    collectibles = map.updateObjects();
                    for(auto & collectible : collectibles)
                    {
                        window.draw(collectible.shape);
                    }
                }
            }
//            player.sprite.setPosition(0, platforms[0].shape.getPosition().y - platforms[0].shape.getSize().y);
            player.sprite.setPosition(0, player.sprite.getPosition().y);

        }
        else if(player.sprite.getPosition().x < 0 )
        {
//            platforms = map1.change(map1.current_map - 1);
            map = mapConnector.maps[mapConnector.current_map - 1];
            mapConnector.current_map--;

            for(auto & plat : map.getPlatforms())
            {
                if(plat.name_id == "platform")
                {
                    collectibles = map.updateObjects();
                    for(auto & collectible : collectibles)
                    {
                        window.draw(collectible.shape);
                    }
                }

            }
            player.sprite.setPosition(window.getSize().x, player.sprite.getPosition().y);
        }


        enemy.move();
        enemy.doDamage(player);

        window.draw(enemy.shape);
        // Update the window
        window.display();
    }

    fmt::println("Collected coins: {}", player.getCoins());
    fmt::println("Hearts: {}", player.getHearts());
    return 0;
}
