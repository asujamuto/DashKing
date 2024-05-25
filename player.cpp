//
// Created by pete on 19.04.24.
//

#include "player.h"
#include <SFML/Graphics.hpp>
#include <fmt/core.h>

//SPRITE WALK ANIMATION
auto walkAnimation(sf::Clock& clock, auto& rectSourceSprite, sf::Sprite& sprite) -> void {
    if(clock.getElapsedTime().asSeconds() > .1f){
        if(rectSourceSprite.left == 130)
        {
            rectSourceSprite.left = 0;
            rectSourceSprite.top += 130;

        }
        else if( rectSourceSprite.top == 130)
        {
            rectSourceSprite.left = 0;
            rectSourceSprite.top = 0;
        }
        else
            rectSourceSprite.left += 130;

        sprite.setTextureRect(rectSourceSprite);
        clock.restart();
    }
};


auto playerMovement(sf::Sprite& sprite) -> void
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.move(sf::Vector2f(0,-.2));
        fmt::println("W pressed");
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.move(sf::Vector2f(0,.2));
        fmt::println("S pressed");
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.move(sf::Vector2f(-.2,0));
        fmt::println("A pressed");
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.move(sf::Vector2f(.2,0));
        fmt::println("D pressed");
    }
}

auto playerBorderCollision(sf::Sprite& sprite, sf::RenderWindow& window) -> void
{
    if(sprite.getPosition().y < 0)
    {
        sprite.setPosition(sprite.getPosition().x,0);
    }
    if(sprite.getPosition().x < 0)
    {
        sprite.setPosition(0,sprite.getPosition().y);
    }

    if(sprite.getPosition().x + sprite.getLocalBounds().width >= window.getSize().x)
    {
        sprite.setPosition(sprite.getPosition().x - 0.2, sprite.getPosition().y);
    }
    if(sprite.getPosition().y + sprite.getLocalBounds().width >= window.getSize().y)
    {

        sprite.setPosition(sprite.getPosition().x , sprite.getPosition().y - 0.2);
    }
}
