//
// Created by pete on 19.04.24.
//

#include <SFML/Graphics.hpp>
#include <fmt/core.h>


static auto walkAnimation(sf::Clock& clock, auto& rectSourceSprite, sf::Sprite& sprite) -> void;
static auto playerMovement(sf::Sprite& sprite) -> void;
static auto playerBorderCollision(sf::Sprite& sprite, sf::RenderWindow& window) -> void;



