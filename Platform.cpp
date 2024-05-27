//
// Created by pete on 26.05.24.
//

#include "Platform.h"

#include "Player.h"

Platform::Platform(
        sf::Vector2f textureSize,
        const sf::Window &window,
        std::string textureName,
        bool collide) :
        GameObject(textureSize, window, textureName){

        is_collising = collide;

}


void Platform::collision(Player* p)
{
    if(is_collising)
    {
        if(sprite.getGlobalBounds().intersects(p -> sprite.getGlobalBounds()))
        {

//            if(p -> sprite.getPosition().x > sprite.getPosition().x
//                and p -> sprite.getPosition().y < sprite.getPosition().y )
//            {
//                p -> sprite.move(sf::Vector2f(-1, 0));
//            }
//            //check 2
//            else if(p -> sprite.getPosition().x < sprite.getPosition().x + sprite.getTextureRect().width
//                    and p -> sprite.getPosition().y < sprite.getPosition().y)
//            {
//                p -> sprite.move(sf::Vector2f(1, 0));
//            }
//            else if(p -> sprite.getPosition().x > sprite.getPosition().x
//                    and p -> sprite.getPosition().y > sprite.getPosition().y)
//            {
//                p -> sprite.setPosition(p -> sprite.getPosition().x,
//                                        p -> sprite.getPosition().y - sprite.getTextureRect().height);
//
//            }
            if(p -> isOnPlatform)
            {
                p -> sprite.setPosition(p -> sprite.getPosition().x,
                                        sprite.getPosition().y - (p -> sprite.getTextureRect().height));
            }
            else if(p -> sprite.getPosition().y <= sprite.getPosition().y and !(p -> isOnPlatform) )
            {
                p -> isOnPlatform = true;
//                p -> sprite.setPosition(p -> sprite.getPosition().x,
//                                        sprite.getPosition().y - (p -> sprite.getTextureRect().height));
                p -> platformHeight = window.getPosition().y - sprite.getTextureRect().height;
            }


//

            fmt::println("X: Block / Player {}/{}", sprite.getPosition().x, p -> sprite.getPosition().x);
            fmt::println("Y: Block / Player {}/{}", sprite.getPosition().y, p -> sprite.getPosition().y);

        }
        else if(!sprite.getGlobalBounds().intersects(p -> sprite.getGlobalBounds()))
        {
            p -> isOnPlatform = false;
            p -> platformHeight = 108;
        }
    }

    if(p -> isOnPlatform)
    {


    }



}
