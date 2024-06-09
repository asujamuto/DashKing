//
// Created by pete on 06.05.24.
//
#include <SFML/Graphics.hpp>
#include "NPC.h"
#include <fmt/core.h>


NPC::NPC(sf::Vector2f sprite_cords, sf::Window const& main_window, std::string const& textureName)
        : GameObject(sprite_cords, main_window, textureName){
    health = 3;
    sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f );
    sprite.setPosition(sf::Vector2f(200, main_window.getSize().y - 349));

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));

    rectangle.setSize(sf::Vector2f(120, 100));
    rectangle.setFillColor(sf::Color(255,255,0,128));
    viewRect = rectangle;
}

//playerMovement left
void NPC::npcMovementLeft()
{
        sprite.move(sf::Vector2f(-xVelocity,0));
        sprite.setScale(-1.f, 1.f);
}

//playerMovement right
void NPC::npcMovementRight()
{
        sprite.move(sf::Vector2f(xVelocity,0));
        sprite.setScale(1.f, 1.f);
}



void NPC::standAnimation()
{
        rect.top = 0;
        if(clock.getElapsedTime().asSeconds() > .5f)
        {
            if(rect.left == 450)
            {
                rect.left = 0;
            }
            else
            {
                rect.left += 150;
            }

            sprite.setTextureRect(rect);
            clock.restart();
        }
}
void NPC::attackAnimation(int howManyTimes)
{
    rect.top = 189.5;
    if(clock.getElapsedTime().asSeconds() > .2f)
    {
        if(rect.left >= 400)
        {
            rect.left = 0;
            attackAnimation_howManyTimes += 1;
        }
        else
        {
            rect.left += 200;
        }

        sprite.setTextureRect(rect);
        clock.restart();
    }

    if(howManyTimes == attackAnimation_howManyTimes)
    {
        attackAnimation_howManyTimes = 0;
        rect.top = 0;
        rect.left = 150;
    }

}

//void NPC::looking(Player& p)
//{
//    if(sprite.getScale().x > 0)
//    {
//        viewRect.setPosition(sprite.getPosition().x + sprite.getTextureRect().width/2, sprite.getPosition().y);
//    }
//    else
//    {
//        viewRect.setPosition( sprite.getPosition().x - sprite.getTextureRect().width, sprite.getPosition().y);
//    }
//
//    if(viewRect.getTextureRect().intersects(p.sprite.getTextureRect()))
//    {
//        attackAnimation();
//    }
//}

void NPC::walkPath(sf::Clock& globalClock)
{
    if(globalClock.getElapsedTime().asSeconds() <= 5.0f)
    {
        standAnimation();
        npcMovementRight();
    }
    else if(globalClock.getElapsedTime().asSeconds() <=  10.0f)
    {
        standAnimation();
        npcMovementLeft();
    }
    else if(globalClock.getElapsedTime().asSeconds() > 10.0f)
    {
        globalClock.restart();
    }


}


void NPC::attackObject()
{
    if(sprite.getScale().x < 0)
    {
        viewRect.setPosition(sf::Vector2f(sprite.getPosition().x - sprite.getTextureRect().width,
                                                  sprite.getPosition().y));

        //dodanie Player p wymaga pointerów, których jeszcze nie umiem
//        if(viewRect.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
//        {
//            attackAnimation(1);
//        }
    }
    else
    {
        viewRect.setPosition(sf::Vector2f(sprite.getPosition().x + sprite.getTextureRect().width/4, sprite.getPosition().y));
//        if(viewRect.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
//        {
//            attackAnimation(1);
//        }
    }


}
