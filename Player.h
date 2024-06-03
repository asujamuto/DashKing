

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

    //Checkable Movement Variables
    bool isJumping = false;
    bool walk = false;
    bool attack = false;
    bool isRunning = false;

    //Checkable Interactions Variables
    bool isOnGround = true;
    float platformHeight = 108.0f;

    sf::RectangleShape attackRect;
    sf::Window window;

    //IMPORTANT PLAYER COMPONETS
    PlayerInterface interface = PlayerInterface(window);
    int health;

    //Animations
    PlayerAnimations animations = PlayerAnimations(texture, rect, sprite, clock);


    Player(sf::Vector2f sprite_cords, sf::Window const& main_window, std::string const& textureName);



    void playerMovement();

    void playerAttack(sf::Clock clock);

    void playerBorderCollision();

    ~Player()
    {
        delete this;
    }


};
