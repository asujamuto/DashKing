#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Player.h"
#include "Map.h"
#include <fmt/core.h>

// Constants



// Main function
int main()
{
    Player player = Player();
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dash King");
    // Set the frame rate limit
    window.setFramerateLimit(60);


    Map map1 = Map(window);
    auto platforms = map1.change(0);
//    auto maps = map1.generateMaps();
    std::vector<Collectible> collectibles;
    std::vector<sf::RectangleShape> hearts = player.Interface(window);




    // Clock for timing
    sf::Clock clock;

    for(auto & plat : platforms)
    {
        if(plat.name_id == "platform")
        {
            collectibles = plat.generateObjects();
        }

    }




    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the screen
        window.clear();

        player.movement(clock, platforms);


        for(auto & heart : hearts)
        {
            window.draw(heart);
        }

        for(auto & plat : platforms)
        {
            map1.update(plat, player);
        }

        // Draw the player
        window.draw(player.sprite);

        // Draw the platforms
        for (auto& platform : platforms)
        {
            window.draw(platform.shape);

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



//        platforms = map1.map_swap(player);
        if(player.sprite.getPosition().x > window.getSize().x )
        {
            platforms = map1.change(map1.current_map + 1);
            for(auto & plat : platforms)
            {
                if(plat.name_id == "platform")
                {
                    collectibles = plat.updateObjects();
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
            platforms = map1.change(map1.current_map - 1);
            for(auto & plat : platforms)
            {
                if(plat.name_id == "platform")
                {
                    collectibles = plat.updateObjects();
                    for(auto & collectible : collectibles)
                    {
                        window.draw(collectible.shape);
                    }
                }

            }
            player.sprite.setPosition(window.getSize().x, player.sprite.getPosition().y);
        }



        // Update the window
        window.display();
    }

    fmt::println("Collected coins: {}", player.getCoins());
    return 0;
}
