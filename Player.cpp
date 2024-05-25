#include "SFML/Graphics.hpp"
#include "fmt/core.h"
#include "fmt/ranges.h"
#include <map>
#include "GameObject.h"
#include "Player.h"
#include "NPC.h"
#include "PlayerInterface.h"


    Player::Player(sf::Vector2f sprite_cords, sf::Vector2f windowCords, std::string const& textureName)
    : GameObject(sprite_cords, windowCords, textureName) {
        health = 3;
        sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f );
        sprite.setPosition(sf::Vector2f(200, windowCords.y - 349));
//        animations(PlayerAnimations(texture, rect, sprite, clock));

        interface = PlayerInterface();
    }




    void Player::playerMovement()
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            walk = true;
            if (sprite.getScale().x < 0) {
                sprite.move(sf::Vector2f(-xVelocity, 0));
            }
            else
            {
                //set sprite to center
                sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
                sprite.setScale(-1.f, 1.f);
                sprite.setPosition(sprite.getPosition());
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            walk = true;
            if (sprite.getScale().x > 0) {
                sprite.move(sf::Vector2f(xVelocity, 0));
            } else {
                sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
                sprite.setScale(1.f, 1.f);
                setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y));
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (!isJumping) {
                isJumping = true;
                yVelocity = -1000.0f; // Prędkość wzbicia się w górę
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
           isRunning = true;
        }

        if (isJumping) {
            // Symulacja ruchu skoku
            float timeUnit = 0.002f; // Jeżeli nie chcemy pracować z Clock ustalamy wartość czasu
            //s = v * t +  0.5 * a * t^2
            float deltaY = yVelocity * timeUnit + 0.5f * gravity * timeUnit * timeUnit;
            sprite.move(0.0f, deltaY);
            fmt::println("{}", deltaY);

            // Zastosowanie grawitacji
            yVelocity += gravity * timeUnit;

            // ziemia
            if (sprite.getPosition().y >= cords.y - 108) {
                isJumping = false;
                sprite.setPosition(sprite.getPosition().x, cords.y - 108);
            }
        }


        if(isRunning and !isJumping)
        {
            xVelocity = DEFAULT_xVELOCITY*3;
            animations.walkAnimation();
            isRunning = false;
        }
        else
        {
            xVelocity = DEFAULT_xVELOCITY;
        }

        if(walk and !isJumping and !isRunning)
        {
            animations.walkAnimation(); walk=false; isRunning=false; }
        else if(isJumping)
        {
            animations.jumpAnimation();
        }
//        else if(!walk and !isRunning and !isJumping and !attack)
//        {
//        }
        else if(!isRunning)
        {

            animations.standAnimation();
        }




    }

    void Player::playerAttack(sf::Clock clock){
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//        {
//            attack = true;
//        }

//       if(attack and !walk and !isJumping)
//       {
//                attackAnimation();

//                animations.attackAnimation(clock);
                animations.alternativeAttackAnimation();

                sf::RectangleShape rectangle(sf::Vector2f(120, 50));

                rectangle.setSize(sf::Vector2f(20, 100));
                rectangle.setFillColor(sf::Color(255,255,0,128));

                if(sprite.getScale().x < 0)
                {
                    rectangle.setPosition(sprite.getPosition().x - 40, sprite.getPosition().y);
                }
                else
                {
                    rectangle.setPosition(sprite.getPosition().x + 20, sprite.getPosition().y);
                }
                attackRect = rectangle;



//                attack = false;

//                sf::Clock attackTime;
//                bool animPlayed = false;
//                if(attackTime.getElapsedTime().asSeconds() > .5f)
//                {
//                   attackAnimation();
//                }
//
//                attack = false;
//                attackClicked = true;
//       }

    }



