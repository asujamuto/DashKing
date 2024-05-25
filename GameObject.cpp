//
// Created by pete on 04.05.24.
//

#include "GameObject.h"

GameObject::GameObject(sf::Vector2f sprite_cords, sf::Vector2f windowCords, const std::string &textureName) {
    texture.loadFromFile(textureName);
    rect = sf::IntRect(0, 0, sprite_cords.x, sprite_cords.y);
    sprite = sf::Sprite(texture, rect);

    clock = sf::Clock();

    cords = windowCords;
}

void GameObject::setPosition(sf::Vector2f pos){
    sprite.setPosition(pos);
}