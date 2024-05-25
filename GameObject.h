
#pragma once
#include "SFML/Graphics.hpp"
#include <map>


struct GameObject {

//    sf::RectangleShape rectangle;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::IntRect rect;

    sf::Clock clock;

    sf::Vector2f cords;

    GameObject(sf::Vector2f sprite_cords, sf::Vector2f windowCords, std::string const& textureName);
    void setPosition(sf::Vector2f pos);



};