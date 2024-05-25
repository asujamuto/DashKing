#include "SFML/Graphics.hpp"
#include "fmt/core.h"
#include <map>
#include "GameObject.h"
#include "Player.h"
#include "NPC.h"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode(1920, 1080), "Jump");
    auto globalClock = sf::Clock();

//    auto background = GameObject(sf::Vector2f(window.getSize().x, window.getSize().y), sf::Vector2f(window.getSize().x, window.getSize().y), "background.jpg");
    auto p = Player(sf::Vector2f(120.0f, 80.0f), sf::Vector2f(window.getSize().x, window.getSize().y), "assets/sprites/FreeKnight_v1/Colour1/Outline/120x80_PNGSheets/_Idle.png");

    auto floor = GameObject(sf::Vector2f(1920, 108), sf::Vector2f(window.getSize().x, window.getSize().y), "assets/env/floor2.png");
//    auto floor = GameObject(sf::Vector2f(1920, 339), sf::Vector2f(window.getSize().x, window.getSize().y), "floor.png");
    auto platform = GameObject(sf::Vector2f(234, 65), sf::Vector2f(window.getSize().x, window.getSize().y), "assets/env/block.png");
    auto ladder = GameObject(sf::Vector2f(39,140), sf::Vector2f(window.getSize().x, window.getSize().y), "assets/env/ladder.png");

    floor.setPosition(sf::Vector2f(0, window.getSize().y - floor.sprite.getTextureRect().height));
    platform.setPosition(sf::Vector2f(window.getSize().x - 700, 600));
    ladder.setPosition(sf::Vector2f(window.getSize().x - 700,  600));
    p.setPosition(sf::Vector2f(0, floor.sprite.getPosition().y));

    auto monster = NPC(sf::Vector2f(150.0f, 200.0f), sf::Vector2f(window.getSize().x, window.getSize().y), "assets/sprites/monster.png");
    auto xanathar = NPC(sf::Vector2f(135.0f, 2.0f), sf::Vector2f(window.getSize().x, window.getSize().y), "assets/sprites/xanathar.png");
    monster.sprite.setPosition(sf::Vector2f(200, floor.sprite.getPosition().y - 20));

//    auto view = sf::View(
//            sf::Vector2f(p.sprite.getPosition().x , p.sprite.getPosition().y ),
//            sf::Vector2f(768 * 1/2 + p.sprite.getTextureRect().width, 432 * 1/2)
//            );
    auto view = sf::View(
            sf::Vector2f(p.sprite.getPosition().x , p.sprite.getPosition().y ),
            sf::Vector2f(768, 432)
    );


//    auto hitboxArea = monster.showHitbox();

    auto runAtackAnimation = false;
    auto pClock = sf::Clock();
    auto attackClock = sf::Clock();
    while(window.isOpen())
    {
            view.setCenter(sf::Vector2f(p.sprite.getPosition().x + 200, p.sprite.getPosition().y - floor.sprite.getTextureRect().height));
            auto event = sf::Event();

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                else if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Q){
                        p.attack = true;
                }
            }

        p.playerMovement();

//        monster.attackAnimation();

        if(p.attack)
        {
            p.animations.attackAnimation(globalClock);
        }

        p.attack = false;

        monster.walkPath(globalClock);
//        monster.standAnimation();


        window.clear();

        window.setView(view);
//        window.draw(backgrdound.sprite);

        window.draw(floor.sprite);
        window.draw(platform.sprite);
        window.draw(ladder.sprite);
        window.draw(monster.sprite);
        window.draw(xanathar.sprite);
        window.draw(monster.viewRect);
//        window.draw(hitboxArea);

        window.draw(p.sprite);
        window.draw(p.attackRect);

        for(auto heart : p.interface.hearts)
        {
            window.draw(heart.sprite);
        }

        window.display();
    }

    return 0;
}
