//
// Created by pete on 10.06.24.
//

#pragma once
#include <fmt/core.h>

#include <json/json.h>
#include <fstream>
#include <iostream>
#include "MapsConnector.h"


Map MapsConnector::updateMap(Player & player)
{
    for(auto & plat : maps[current_map].platforms)
    {
       if(plat.drawable)
       {
          window->draw(plat.shape);
       }
    }
    for(auto & c : maps[current_map].collectibles)
    {
        if(player.sprite.getGlobalBounds().intersects(c->shape.getGlobalBounds()))
        {
            fmt::println("Collected coins: {}, Coin id: {}", player.getCoins(), c -> id);

//                map.removeCollectible(*c);
            player.addCoins(1, c -> collectable);
            c->collectable= false;
        }
        else if(c->collectable)
        {
            window -> draw(c -> shape);
        }

    }

    for(auto & enemy : maps[current_map].enemies)
    {
        if(player.attackRectangle.getGlobalBounds().intersects(enemy->shape.getGlobalBounds()))
        {
            enemy->shape.move(2, 0);
            enemy->changeHeartsAmount(1);
        }
        if(enemy->getHearts() <= 0)
        {
            continue;
        }
        else
        {
            enemy->move();
            enemy->doDamage(player);
            window -> draw(enemy->shape);
        }

    }

    //Go to next map
    if(player.sprite.getPosition().x + player.sprite.getSize().x > window -> getSize().x )
    {
            current_map = current_map + 1;
            clock.restart();
            player.sprite.setPosition(0, player.sprite.getPosition().y);

    }
   //Go to previous map
    if(player.sprite.getPosition().x < 0 )
    {

        current_map = current_map - 1;
        clock.restart();
        player.sprite.setPosition(window -> getSize().x - player.sprite.getSize().x, player.sprite.getPosition().y);
    }
    try
    {
        return maps[current_map];
    }
    catch (std::exception const & e)
    {
        current_map = current_map -1;
        player.sprite.setPosition(player.sprite.getPosition().x - player.sprite.getSize().x, player.sprite.getPosition().y);
        return maps[current_map - 1];
    }
}

void MapsConnector::updatePlatform(Player & player)
{

    for(auto & plat : maps[current_map].platforms)
    {

        if(plat.name_id == "lift")
        {
//            fmt::println("{}", clock.getElapsedTime().asSeconds());
            fmt::println("wysokość windy: {}", plat.shape.getPosition().y);
            fmt::println("czas: {}", clock.getElapsedTime().asSeconds());
//            auto original_cords = plat.shape.getPosition();
            if(clock.getElapsedTime().asSeconds() <= 7.0f)
            {
                plat.shape.move(0, -2);
            }
            else if(clock.getElapsedTime().asSeconds() > 7.0f &&
            clock.getElapsedTime().asSeconds() < 14.0f)
            {
                plat.shape.move(0, 2);
            }
            else
            {
                plat.shape.move(0, 2);
                if(clock.getElapsedTime().asSeconds() >= 14.0f)
                {
                    clock.restart();
                }
            }
        }
    }

}

Map MapsConnector::change(int map_index)
{
    Map map = maps[map_index];
    clock.restart();
    return map;
}