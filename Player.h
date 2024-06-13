//
// Created by pete on 09.06.24.
//plakat 48hfp

#ifndef DASHKING_PLAYER_H
#define DASHKING_PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Utils.h"
#include "Platform.h"


class Player {

    private:
        int coins = 0;
        int hearts = 3;
    //movement variables
    public:
        bool isJumping = false;
        float velocityY = 0.0f;
        const float GRAVITY = 380.0f;
        const float JUMP_STRENGTH = -350.0f;
        const float MOVE_SPEED = 200.0f;
        const float RUN_SPEED = 400.0f;

        sf::RectangleShape sprite;
        std::vector <sf::RectangleShape> health;


    Player()
    {
        sf::RectangleShape player(sf::Vector2f(30, 40));
        player.setFillColor(sf::Color::Green);
        player.setPosition(10, 500);
        sprite = player;
    }

    void movement(sf::Clock& deltaTime,
              std::vector <Platform>& platforms
              );

    //Interface


    //health


    //coins
    int getCoins();
    int addCoins(int amount = 1);

    std::vector<sf::RectangleShape> Interface(const sf::RenderWindow & window);

};


#endif //DASHKING_PLAYER_H
