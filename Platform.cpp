//
// Created by pete on 26.05.24.
//
#include "Platform.h"
#include "Player.h"


Platform::Platform (
        sf::Vector2f textureSize,
        const sf::Window &window,
        std::string textureName,
        bool collide) :
        GameObject(textureSize, window, textureName){

        is_collising = collide;
        current_platform = false;

}


//bool Platform::collision(Player& p) {
//
////    if (is_collising) {
////        if (sprite.getGlobalBounds().intersects(p->sprite.getGlobalBounds()))
////        {
////
////            if ( sprite.getPosition().y < p. sprite.getPosition().y
////                and p. sprite.getPosition().x > sprite.getPosition().x
////                and p. sprite.getPosition().x < sprite.getPosition().x + sprite.getGlobalBounds().width)
////            {
////                fmt::println("can't reach");
////                p-> offGround = false;
////                p->platformHeight = window.getPosition().y - sprite.getGlobalBounds().height;
////                p. sprite.move(sf::Vector2f(p. sprite.getPosition().x, sprite.getPosition().y - 100));
////
////
////
////            }
////            else if(sprite.getPosition().y > p. sprite.getPosition().y
////                    and p. sprite.getPosition().x > sprite.getPosition().x
////                    and p. sprite.getPosition().x < sprite.getPosition().x + sprite.getGlobalBounds().width)
////            {
////                fmt::println("under platform");
////                p. offGround = true;
////            }
////
////
////            if (!(p->offGround))
////            {
////                fmt::println("X: Block / Player {}/{}", sprite.getPosition().x, p->sprite.getPosition().x);
////                fmt::println("Y: Block / Player {}/{}", sprite.getPosition().y, p->sprite.getPosition().y);
////
////            }
////
////        }
////        else if (!sprite.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) {
////            fmt::println("nie dotyka");
////            p->offGround = false;
////            p->platformHeight = 108;
////        }
//
//        return sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds());
//}

int Platform::resolveCollision(GameObject& p)
{
    if(sprite.getGlobalBounds().intersects(p.sprite.getGlobalBounds()))
    {

        auto rect1 = p.sprite.getGlobalBounds();
        auto rect2 = sprite.getGlobalBounds();

        float dx = (rect1.left + rect1.width / 2) - (rect2.left + rect2.width / 2);
        float dy = (rect1.top + rect1.height / 2) - (rect2.top + rect2.height / 2);
        float intersectX = std::abs(dx) - (rect1.width / 2 + rect2.width / 2);
        float intersectY = std::abs(dy) - (rect1.height / 2 + rect2.height / 2);

        if (intersectX > intersectY)
        {
            if (dx > 0) {
                p.sprite.move(-intersectX, 0);
            }
            else {
                p.sprite.move(intersectX, 0);
            }
        }
        else
        {
            if (dy > 0)
            {
                p.sprite.move(0, -intersectY);
            }
            else {
            p.sprite.move(0, intersectY);
            }
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

