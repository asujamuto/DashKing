
#include "SFML/Graphics.hpp"
#include "fmt/core.h"
#include "fmt/ranges.h"
#include "Player.h"
#include "NPC.h"
#include "PlayerInterface.h"
#include "Platform.h"


Player::Player(sf::Vector2f sprite_cords, sf::Window const& main_window, std::string const& textureName)
    : GameObject(sprite_cords, main_window, textureName) {
        health = 3;
        sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f );
        sprite.setPosition(sf::Vector2f(200, window.getSize().y - 349));

//        animations(PlayerAnimations(texture, rect, sprite, clock));
    }




    void Player::playerMovement(GameObject& floor, sf::Clock & jumpClock_main)
    {
        if (
             !(floor.sprite.getPosition().x + floor.sprite.getGlobalBounds().width < sprite.getPosition().x
             && floor.sprite.getPosition().x > sprite.getPosition().x))
        {
           fmt::println("Out of the border");
        }
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
            if (sprite.getScale().x > 0)
            {
                sprite.move(sf::Vector2f(xVelocity, 0));
            }
            else
            {
                sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
                sprite.setScale(1.f, 1.f);
                setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y));
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and !offGround) {
//            if (!isJumping ) {
//                isJumping = true;
//                yVelocity = -1000.0f; // Prędkość wzbicia się w górę
//            }
            sprite.move(0.f, -yVelocity);
            offGround = true;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
           isRunning = true;
        }

        float deltaY;
        if (offGround) {
            if(jumpClock_main.getElapsedTime().asSeconds() < .5)
            {
                deltaY = yVelocity + jumpClock_main.getElapsedTime().asSeconds() + .5f * gravity * jumpClock_main.getElapsedTime().asSeconds() * jumpClock_main.getElapsedTime().asSeconds();
                yVelocity += gravity * jumpClock_main.getElapsedTime().asSeconds();
                sprite.move(0.0f, -deltaY);
                gravity = gravity / 2;
            }
            else if(jumpClock_main.getElapsedTime().asSeconds() >= .5) {
                deltaY = yVelocity + jumpClock_main.getElapsedTime().asSeconds() +
                         .5f * gravity * jumpClock_main.getElapsedTime().asSeconds() *
                         jumpClock_main.getElapsedTime().asSeconds();
                yVelocity += gravity * jumpClock_main.getElapsedTime().asSeconds();
                sprite.move(0.0f, deltaY);
                fmt::println("fall");

                if (floor.sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
                    offGround = false;
                    jumpClock_main.restart();
                }


            }


//            if(floor.sprite.getLocalBounds().intersects(sprite.getLocalBounds()))
//            {
//                offGround = false;
//                jumpClock_main.restart();
//            }

            fmt::println("czas skoku: {}", jumpClock_main.getElapsedTime().asSeconds());

            // Symulacja ruchu skoku
//            float timeUnit = 0.002f; // Jeżeli nie chcemy pracować z Clock ustalamy wartość czasu
//            //s = v * t +  0.5 * a * t^2
//            float deltaY = yVelocity * timeUnit + 0.5f * gravity * timeUnit * timeUnit;
//            sprite.move(0.0f, deltaY);
//            // Zastosowanie grawitacji
//            yVelocity += gravity * timeUnit;
//
//            if(offGround)
//            {
//                if (sprite.getPosition().y >= cords.y - platformHeight) {
//                    isJumping = false;
//                    sprite.setPosition(sprite.getPosition().x, cords.y -  platformHeight);
//                }
//            }
//            // ziemia
//            else
//            {
//                if (sprite.getPosition().y >= cords.y - 108) {
//                    isJumping = false;
//                    sprite.setPosition(sprite.getPosition().x, cords.y -  108);
//                }
//            }

        }

        if(isRunning and !offGround)
        {
            xVelocity = DEFAULT_xVELOCITY*3;
            animations.walkAnimation();
            isRunning = false;
        }
        else
        {
            xVelocity = DEFAULT_xVELOCITY;
        }

        if(walk and !offGround and !isRunning)
        {
            animations.walkAnimation();
            walk=false;
        }
        else if(offGround)
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



