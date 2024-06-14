//
// Created by pete on 13.06.24.
//

#ifndef DASHKING_ENEMY_H
#define DASHKING_ENEMY_H

#include "GameObject.h"
#include "Player.h"

class Enemy : public GameObject<sf::RectangleShape> {

    private:
        int damage;

    public:
        bool isJumping = false;

        float velocityY = 0.0f;
        const float GRAVITY = 380.0f;
        const float JUMP_STRENGTH = -350.0f;
        const float MOVE_SPEED = 200.0f;
        const float RUN_SPEED = 400.0f;
        sf::Clock movementClock;

        Enemy(const sf::Vector2f size, const sf::Vector2f position, int damage);

        void doDamage(Player & p);
        void move();

};


#endif //DASHKING_ENEMY_H
