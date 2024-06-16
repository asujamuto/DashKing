//
// Created by pete on 13.06.24.
//

#include "Enemy.h"
#include "Utils.h"

Enemy::Enemy(const sf::Vector2f size, const sf::Vector2f position, int damage = 1) : GameObject<sf::RectangleShape>(size, position)
        {
            shape.setFillColor(sf::Color::Red);
            damage = damage;
        }

void Enemy::doDamage(Player &player) {


    if(Utils::isColliding(player.sprite, shape))
    {
//        if(Utils::resolveCollision(player.sprite, shape, player.velocityY))
//        {
            player.sprite.move(-30, 0);
            player.changeHeartsAmount(1);

//        }
    }
}

void Enemy::move()
{
    if(movementClock.getElapsedTime().asSeconds() < 4.0f)
    {
        shape.move(2, 0);
    }
    else if(movementClock.getElapsedTime().asSeconds() >= 4.0f && movementClock.getElapsedTime().asSeconds() < 8.0f )
    {
        shape.move(-2, 0);
    }
    else
    {
        movementClock.restart();
    }
}

int Enemy::getHearts()
{
    return health;
}

int Enemy::changeHeartsAmount(int amount)
{
    health = health - 1;
    return health;
}