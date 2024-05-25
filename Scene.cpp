//
// Created by pete on 06.05.24.
//

#include "Scene.h"
#include "Player.h"

Scene::Scene(GameObject background,
             GameObject floor,
             Player player,
             sf::Vector2f windowCords) {

    floor.setPosition(sf::Vector2f(0, windowCords.y - floor.sprite.getTextureRect().height));
    background.setPosition(sf::Vector2f(0,0));
    player.setPosition(sf::Vector2f(0, floor.sprite.getPosition().y));

//    renderSprites.push_back(background);
//    renderSprites.push_back(floor);
//    renderSprites.push_back(player);

}