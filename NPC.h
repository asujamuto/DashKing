//
// Created by pete on 06.05.24.
//

#pragma once


#include "SFML/Graphics.hpp"
#include <map>
#include "GameObject.h"
#include "Player.h"
#include <vector>


struct NPC : public GameObject {
    float xVelocity = 0.2f; // Prędkość po osi x
    float yVelocity = 0.0f; // Prędkość po osi y
    float gravity = 1500.0f; // Wartość grawitacji

    bool isJumping = false;
    bool walk = false;
    bool attack = false;

    //IMPORTANT NPC COMPONETS
    int health = 3;
    sf::RectangleShape viewRect;
    int viewRange = 20;



    NPC(sf::Vector2f sprite_cords, sf::Vector2f windowCords, std::string const& textureName);

    void npcMovementLeft();
    void npcMovementRight();



    void standAnimation();
    void attackAnimation();

//    void looking(Player& p);
    void walkPath(sf::Clock& globalClock);

//    sf::ConvexShape showHitbox();



};