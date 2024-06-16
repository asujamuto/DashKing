//
// Created by pete on 10.06.24.
//

#include "Utils.h"
#include <SFML/Graphics.hpp>

// Function to handle collisions
bool Utils::resolveCollision(sf::RectangleShape& player, const sf::RectangleShape& platform, float& velocityY) {
    sf::FloatRect playerBounds = player.getGlobalBounds();
    sf::FloatRect platformBounds = platform.getGlobalBounds();

    // Check if player is intersecting with the platform
    if (playerBounds.intersects(platformBounds)) {
        // Calculate intersection depth
        float overlapLeft = playerBounds.left + playerBounds.width - platformBounds.left;
        float overlapRight = platformBounds.left + platformBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - platformBounds.top;
        float overlapBottom = platformBounds.top + platformBounds.height - playerBounds.top;

        bool fromLeft = overlapLeft < overlapRight;
        bool fromTop = overlapTop < overlapBottom;

        float minOverlapX = fromLeft ? overlapLeft : overlapRight;
        float minOverlapY = fromTop ? overlapTop : overlapBottom;

        // Resolve collision based on the minimum overlap
        if (minOverlapX < minOverlapY) {
            // Resolve horizontal collision
            if (fromLeft) {
                player.setPosition(platformBounds.left - playerBounds.width, playerBounds.top);
            } else {
                player.setPosition(platformBounds.left + platformBounds.width, playerBounds.top);
            }
        } else {
            // Resolve vertical collision
            if (fromTop) {
                player.setPosition(playerBounds.left, platformBounds.top - playerBounds.height);
                velocityY = 0;
                return true;
            } else {
                player.setPosition(playerBounds.left, platformBounds.top + platformBounds.height);
                velocityY = 0;
            }
        }
    }
    return false;
}

bool Utils::isColliding(sf::RectangleShape &player, const sf::RectangleShape &shape) {
    return player.getGlobalBounds().intersects(shape.getGlobalBounds());
}

bool Utils::isTextClicked(const sf::Text &text, const sf::RenderWindow & window)
{
    return text.getGlobalBounds().contains(
            sf::Mouse::getPosition(window).x,
            sf::Mouse::getPosition(window).y
    );

}
//isColliding for collectibles (coins, keys etc.)
//bool Utils::isColliding(const & Player  A, const &  Collectible  B) {
//    return A.sprite.getGlobalBounds().intersects(B.shape.getGlobalBounds());
//}

//isColliding for objects
//bool Utils::isColliding(const  GameObject<sf::RectangleShape>& A, const  GameObject<sf::RectangleShape>& B) {
//    return A.shape.getGlobalBounds().intersects(B.shape.getGlobalBounds());
//}


