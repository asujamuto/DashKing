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
    sf::RectangleShape  viewRect;
    int viewRange = 20;

    //ANIMATION VARIABLES
    int attackAnimation_howManyTimes = 0;



    NPC(sf::Vector2f sprite_cords, sf::Window const& main_window, std::string const& textureName);

    void npcMovementLeft();
    void npcMovementRight();



    void standAnimation();
    void attackAnimation(int howManyTimes);

//    void looking(Player& p);
    void walkPath(sf::Clock& globalClock);


    //dodanie Player p wymaga pointerów, których jeszcze nie umiem
    //void attackObject(Player& p);
    void attackObject();

//    sf::ConvexShape showHitbox();



};