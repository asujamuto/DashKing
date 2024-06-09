

#include "PlayerAnimations.h"
#include "SFML/Graphics.hpp"
#include "fmt/core.h"
#include "fmt/ranges.h"




PlayerAnimations::PlayerAnimations(sf::Texture& texture, sf::IntRect& rect, sf::Sprite& sprite, sf::Clock& clock) :
clock(clock), texture(texture), rect(rect), sprite(sprite)
{
    fmt::println("Animations utworzone");
}


void PlayerAnimations::standAnimation(){
    texture.loadFromFile(animationPath + "_Idle.png");
    if (clock.getElapsedTime().asSeconds() > .1f) {
        if (rect.left == 1120)
        {
            rect.left = 40;
            rect.width = 32;

            rect.top = 40;
            rect.height = 40;
        }
        else
        {
            rect.left += 120;
        }

        sprite.setTextureRect(rect);
        clock.restart();
    }
}
//SPRITE WALK ANIMATION
void PlayerAnimations::walkAnimation(){
    texture.loadFromFile(animationPath + "_Run.png");
    if (clock.getElapsedTime().asSeconds() > .1f) {
        if (rect.left >= 1120)
        {
            rect.left = 40;
            rect.width = 32;

            rect.top = 40;
            rect.height = 40;

        }
        else
        {
            rect.left += 120;
        }

        sprite.setTextureRect(rect);
        clock.restart();
    }
}

void PlayerAnimations::jumpAnimation() {
    texture.loadFromFile(animationPath + "_Jump.png");
    rect.left = 40;
    rect.width = 32;
    rect.top = 40;
    rect.height = 40;
    sprite.setTextureRect(rect);
}

void PlayerAnimations::attackAnimation(sf::Clock& globalClock) {
    texture.loadFromFile(animationPath + "_Attack2.png");
    if (clock.getElapsedTime().asSeconds() > .5f) {
        if (rect.left >= 480)
        {
            rect.left   = 40;
            rect.width  = 32;
            rect.top    = 40;
            rect.height = 40;
        }
        else
        {
            rect.left += 120;
        }
        sprite.setTextureRect(rect);
        clock.restart();
    }


}

void PlayerAnimations::dashAnimaton(){

    texture.loadFromFile(animationPath + "_Dash.png");
    if (clock.getElapsedTime().asSeconds() > .1f) {
        if (rect.left == 120)
        {
            rect.left = 0;
        }
        else
        {
            rect.left += 120;
        }
    }
    sprite.setTextureRect(rect);
    clock.restart();
}


void PlayerAnimations::alternativeAttackAnimation()
{
    texture.loadFromFile(animationPath + "_Attack2.png");
//    rect.left = 240;
    rect.left   = 270;
    rect.width  = 80;
    rect.top    = 40;
    rect.height = 40;
    sprite.setTextureRect(rect);

}
