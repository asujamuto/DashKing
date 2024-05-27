
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

    sf::Window window;

    GameObject(sf::Vector2f sprite_cords, sf::Window const& main_window, std::string const& textureName);
    GameObject(sf::Vector2f sprite_cords, sf::Vector2f window_cords, std::string const& textureName);
    void setPosition(sf::Vector2f pos);
    virtual ~GameObject();


};