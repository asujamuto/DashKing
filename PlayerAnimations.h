//
// Created by pete on 12.05.24.
//

#pragma once
#include "SFML/Graphics.hpp"



struct PlayerAnimations {

    sf::Texture& texture;
    sf::IntRect& rect;
    sf::Sprite& sprite;
    sf::Clock& clock;

    std::string animationPath = "assets/sprites/FreeKnight_v1/Colour1/Outline/120x80_PNGSheets/";

    PlayerAnimations(sf::Texture& texture, sf::IntRect& rect, sf::Sprite& sprite, sf::Clock& clock);

    void standAnimation();
    void jumpAnimation();
    void attackAnimation(sf::Clock& globalClock);
    void dashAnimaton();
    void alternativeAttackAnimation();
    //SPRITE WALK ANIMATION
    void walkAnimation();

};


