//
// Created by pete on 09.06.24.
//

#include "Player.h"
#include <fmt/core.h>
void Player::movement(sf::Clock& clock, std::vector<Platform> & platforms)
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
        moveX -= currentMoveSpeed * deltaTime - xVelocity;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        moveX += currentMoveSpeed * deltaTime + xVelocity;
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

int Player::changeHeartsAmount(int amount)
{
    hearts = hearts - amount;
    if(hearts < 3)
    {
        fmt::println("Game over");
    }
    return hearts;
}

int Player::getCoins() {
    return coins;
}

int Player::addCoins(int amount, bool collectable) {
    if(collectable)
    {
        coins += amount;
    }
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
void Player::attack()
{

    sf::RectangleShape rectangle(sf::Vector2f(120, 50));

    rectangle.setSize(sf::Vector2f(20, 100));
    rectangle.setFillColor(sf::Color::Yellow);

    if(sprite.getScale().x < 0)
    {
        rectangle.setPosition(sprite.getPosition().x - sprite.getSize().x - 20, sprite.getPosition().y);
    }
    else
    {
        rectangle.setPosition(sprite.getPosition().x + sprite.getSize().x + 20, sprite.getPosition().y);
    }
    attackRectangle = rectangle;




}
void Player::update()
{
    window -> draw(sprite);
    if(isAttacking)
    {
        window -> draw(attackRectangle);
        isAttacking = false;
    }
    if(hearts < 0)
    {
        window->clear();
        window->close();
        window.release();
    }
    for(int i =0; i < hearts; i++)
    {

        window -> draw(health[i]);

    }



}