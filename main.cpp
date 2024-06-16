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
            Platform(sf::Vector2f(window.getSize().x, window.getSize().y), sf::Vector2f(0, 550), "enemyPlatform")
    };
    std::vector<Platform> map1 = {
            Platform(sf::Vector2f(200, window.getSize().y), sf::Vector2f(0, 550), "platform"),
            Platform(sf::Vector2f(200, window.getSize().y), sf::Vector2f(200,400), "default"),
            Platform(sf::Vector2f(200, window.getSize().y), sf::Vector2f(400,300), "default"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 500), "enemyPlatform"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, 840), "lift"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 900), "platform"),
            Platform(sf::Vector2f(500, 60), sf::Vector2f(window.getSize().x - 200, window.getSize().y - 240), "platform"),


    };
    std::vector map2 = {
            Platform(sf::Vector2f(500, 30), sf::Vector2f(-50, window.getSize().y - 240), "platform"),
            Platform(sf::Vector2f(200, 20), sf::Vector2f(250,200), "platform"),
            Platform(sf::Vector2f(200, 20), sf::Vector2f(550,800), "lift"),
            Platform(sf::Vector2f(500, 20), sf::Vector2f(650, 920), "platform"),
            Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, 800), "lift"),
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
    std::vector<Platform> map4 = {
            Platform(sf::Vector2f(window.getSize().x, window.getSize().y), sf::Vector2f(0, 550), "bossMap")
    };

    //push back KOPIUJE obiek, a emplace_back dodaje go bezpośrednio do vectora
    mapConnector.maps.emplace_back(map0);
    mapConnector.maps.emplace_back(map1);
    mapConnector.maps.emplace_back(map2);
    mapConnector.maps.emplace_back(map3);
    mapConnector.maps.emplace_back(map4);
    Map map = mapConnector.maps[mapConnector.current_map];

    Player player = Player();
//    auto maps = map1.generateMaps();
    std::vector<Collectible> collectibles;
    std::vector<sf::RectangleShape> hearts = player.Interface(window);
    Enemy enemy = Enemy(sf::Vector2f(30, 40), sf::Vector2f(600, 550 - 40), 3);

    sf::Clock clock;
    bool attack = false;


    while (window.isOpen())
    {


        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || player.getHearts() <= 0 )
            {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Q){
                attack = true;
                fmt::println("Q pressed");
                fmt::println("Attack rect x {}", player.attackRectangle.getPosition().x);
                fmt::println("Attack rect y {}", player.attackRectangle.getPosition().y);
                window.draw(player.attackRectangle);
                player.attack();
            }

        }

        //clear the screen
        window.clear();



        window.draw(player.sprite);

        for(int i =0; i < player.getHearts(); i++)
        {
            window.draw(hearts[i]);
        }

        player.movement(clock, map.platforms);



        if(attack)
        {
            window.draw(player.attackRectangle);
            attack = false;
        }

        mapConnector.updatePlatform(player);
        map = mapConnector.updateMap(player);


        // Update the window
        window.display();

    }

    fmt::println("Collected coins: {}", player.getCoins());
    fmt::println("Hearts: {}", player.getHearts());
    return 0;
}
