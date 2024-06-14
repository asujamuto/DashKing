//
// Created by pete on 09.06.24.
//

#include "Player.h"

void Player::movement(sf::Clock& clock, std::vector<Platform>& platforms)
{
    // Get the time since the last frame
    float deltaTime = clock.restart().asSeconds();

    // Determine move speed (normal or running)
    float currentMoveSpeed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ? RUN_SPEED : MOVE_SPEED;

    // Handle jump start
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && !isJumping)
    {
        isJumping = true;
        velocityY = JUMP_STRENGTH;
    }

    // Horizontal movement
    float moveX = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        moveX -= currentMoveSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveX += currentMoveSpeed * deltaTime;
    }
    sprite.move(moveX, 0);

    // Apply gravity if jumping
    if (isJumping)
    {
        velocityY += GRAVITY * deltaTime;
        sprite.move(0, velocityY * deltaTime);

        bool landed = false;
        // Check for collision with platforms
        for (const auto& platform : platforms)
        {
            if (Utils::resolveCollision(sprite, platform.shape, velocityY))
            {
                landed = true;
            }
        }

        // If the player has landed on a platform, stop jumping
        if (landed)
        {
            isJumping = false;
        }
    }
    else
    {
        // Check if player is standing on a platform
        bool onPlatform = false;
        for (const auto & platform : platforms)
        {
            if (sprite.getGlobalBounds().intersects(platform.shape.getGlobalBounds()))
            {
                break;
            }
        }

        // If not on any platform, start falling
        if (!onPlatform)
        {
            isJumping = true;
        }
    }

}

int Player::getHearts() {
    return hearts;
}

int Player::changeHeartsAmount(int amount) {
    hearts = hearts - amount;
    return hearts;
}

int Player::getCoins() {
    return coins;
}

int Player::addCoins(int amount) {
    coins += amount;
    return coins;
}

std::vector<sf::RectangleShape> Player::Interface(const sf::RenderWindow & window)
{
    for(int i = 0; i < hearts; i++)
    {
        health.push_back( sf::RectangleShape(sf::Vector2f(20, 20)) );
        health[i].setPosition(health[i].getSize().x + (40 * i),
                              window.getPosition().y + 10);
        health[i].setFillColor(sf::Color::Red);
    }

    return health;
}