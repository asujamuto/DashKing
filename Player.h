

#pragma once


#include "SFML/Graphics.hpp"
#include "fmt/core.h"
#include <map>
#include "PlayerAnimations.h"
#include "NPC.h"
#include "Player.h"
#include "PlayerInterface.h"



struct Player : public GameObject {

    const float DEFAULT_xVELOCITY = .2f;
    const float DEFAULT_yVELOCITY = 0.0f;
    float xVelocity = DEFAULT_xVELOCITY; // Prędkość po osi x
    float yVelocity = 0.0f; // Prędkość po osi y
    float gravity = 2000.0f; // Wartość grawitacji

    bool isJumping = false;
    bool walk = false;
    bool attack = false;
    bool isRunning = false;

    sf::RectangleShape attackRect;


    //IMPORTANT PLAYER COMPONETS
    PlayerInterface interface;
    int health;

    //Animations
    PlayerAnimations animations = PlayerAnimations(texture, rect, sprite, clock);

    Player(sf::Vector2f sprite_cords, sf::Vector2f windowCords, std::string const& textureName);



    void playerMovement();

    void playerAttack(sf::Clock clock);


};
