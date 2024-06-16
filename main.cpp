#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Player.h"
#include "MapsConnector.h"
#include <fmt/core.h>
#include "Enemy.h"
//#include <optional>

// Constants



// Main function
int main()
{

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Dash King");
    // Set the frame rate limit
    window.setFramerateLimit(60);

    //Connecting All Maps In One
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
    Map map = mapConnector.maps[mapConnector.current_map];

    Player player = Player();
//    auto maps = map1.generateMaps();
    std::vector<Collectible> collectibles;
    std::vector<sf::RectangleShape> hearts = player.Interface(window);
    Enemy enemy = Enemy(sf::Vector2f(30, 40), sf::Vector2f(600, 550 - 40), 3);




    // Clock for timing
    sf::Clock clock;





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

        //clear the screen
        window.clear();

//        for(auto & c : map.collectibles)
//        {
//            fmt::println("{}", c.id);
//            window.draw(c.shape);
//            map.removeCollectible(c);
//            player.addCoins();
//        }
        for (auto it = collectibles.begin(); it != collectibles.end(); /* no increment here */) {
            fmt::println("Coin: {}", it->id);
            if(player.sprite.getGlobalBounds().intersects(it -> shape.getGlobalBounds()))
            {
                player.addCoins();
                it = map.removeCollectible(it);
            }
            else
            {
                window.draw(it->shape);
            }

        }

        window.draw(player.sprite);

        for(int i =0; i < player.getHearts(); i++)
        {
            window.draw(hearts[i]);
        }

        player.movement(clock, map.platforms);



        enemy.move();
        enemy.doDamage(player);
        window.draw(enemy.shape);


        mapConnector.updatePlatform(player);
        map = mapConnector.updateMap(player);

        // Update the window
        window.display();

    }

    fmt::println("Collected coins: {}", player.getCoins());
    fmt::println("Hearts: {}", player.getHearts());
    return 0;
}
