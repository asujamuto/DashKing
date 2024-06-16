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
    return maps[current_map];
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
            auto original_cords = plat.shape.getPosition();
            if(clock.getElapsedTime().asSeconds() <= 7.0f)
            {
                plat.shape.move(0, -2);
            }
            else if(clock.getElapsedTime().asSeconds() > 7.0f &&
            clock.getElapsedTime().asSeconds() < 14.0f)
            {
                plat.shape.move(0, 2);
            }
            else if(clock.getElapsedTime().asSeconds() > 14.0f or plat.shape.getPosition().y < -2)
            {
                plat.shape.move(0, -2);
                if(plat.shape.getPosition() == original_cords)
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