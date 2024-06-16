//
// Created by pete on 09.06.24.
//plakat 48hfp

#ifndef DASHKING_PLAYER_H
#define DASHKING_PLAYER_H

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Utils.h"
#include "Platform.h"
#include <memory>
#include <nlohmann/json.hpp>
#include <fstream>


class Player {

    private:
        int coins;
        int hearts;
        std::unique_ptr<sf::RenderWindow> window = nullptr;
        nlohmann::json jsonData;
    //movement variables
    public:
        bool isJumping = false;
        float velocityY = 0.0f;
        float xVelocity = 1;
        const float GRAVITY = 380.0f;
        const float JUMP_STRENGTH = -350.0f;
        const float MOVE_SPEED = 200.0f;
        const float RUN_SPEED = 400.0f;

        bool isAttacking = false;
        bool dead = false;

        sf::RectangleShape sprite;
        std::vector <sf::RectangleShape> health;

        sf::RectangleShape attackRectangle;

    Player(sf::RenderWindow & main_window)
    {
        std::ifstream jsonFileStream("Player.json");
        jsonData = nlohmann::json::parse(jsonFileStream);

        hearts = jsonData["hearts"];
        coins = jsonData["coins"];
        xVelocity = jsonData["xVelocity"];
        sf::RectangleShape player(sf::Vector2f(30, 40));
        player.setFillColor(sf::Color::Green);
        player.setPosition(10, 500);
        sprite = player;

        window = std::unique_ptr<sf::RenderWindow>(&main_window);
    }


    void update();
    void movement(sf::Clock& deltaTime, std::vector<Platform>& platforms);



    //Interface


    //health
    int getHearts();
    int changeHeartsAmount(int amount = 0);



    //coins
    int getCoins();
    int addCoins(int amount = 1, bool collectable = true);

    void attack();
    std::vector<sf::RectangleShape> Interface(const sf::RenderWindow & window);

    ~Player()
    {
        window.release();
    }
};


#endif //DASHKING_PLAYER_H
