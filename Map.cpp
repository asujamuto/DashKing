//
// Created by pete on 10.06.24.
//

#include "Map.h"
#include <fmt/core.h>

#include <json/json.h>
#include <fstream>
#include <iostream>




//template <typename T>
void Map::update(Platform& plat, Player & player)
{

    if(plat.name_id == "lift")
    {
        fmt::println("{}", clock.getElapsedTime().asSeconds());
        auto original_cords = plat.shape.getPosition();
        if(clock.getElapsedTime().asSeconds() <= 7.0f)
        {
            plat.shape.move(0, -2);
        }
        else if(clock.getElapsedTime().asSeconds() > 7.0f &&
                clock.getElapsedTime().asSeconds() < 16.0f)
        {
            plat.shape.move(0, 2);
        }
        else
        {
            plat.shape.move(0, -2);
            if(plat.shape.getPosition() == original_cords)
            {
                clock.restart();
            }
        }
    }

//    for (auto& platform : platforms)
//    {
//
//        for(int i = 0; i < platform.collectibles.size(); i++)
//        {
//            if(player.sprite.getGlobalBounds().intersects(platform.collectibles[i].shape.getGlobalBounds()))
//            {
//                platform.removeCollectible(platform.collectibles[i]);
//                player.addCoins();
//                fmt::println("touching {}", i);
//            }
//
//
//        }
//
//        for(auto & spike : platform.spikes)
//        {
//
//        }
//
//    }


}

//std::vector<Platform>& Map::map_swap(Player & player)
//{
//    if(player.sprite.getPosition().x > window -> getSize().x and current_map == 0)
//    {
//        platforms = change(1);
////            player.sprite.setPosition(0, platforms[0].shape.getPosition().y - platforms[0].shape.getSize().y);
//        player.sprite.setPosition(0, player.sprite.getPosition().y);
//
//    }
//    else if(player.sprite.getPosition().x > window -> getSize().x and current_map == 1)
//    {
//        platforms = change(2);
//        player.sprite.setPosition(0, player.sprite.getPosition().y);
//    }
//    else if(player.sprite.getPosition().x < 0 and current_map == 1)
//    {
//        platforms = change(0);
//        player.sprite.setPosition(window -> getSize().x, player.sprite.getPosition().y);
////            player.sprite.setPosition(0, platforms[platforms.size() -1].shape.getPosition().y - platforms[platforms.size() - 1].shape.getSize().y);
//
//    }

//    if(player.sprite.getPosition().x > window -> getSize().x)
//    {
//        try
//        {
//            platforms = change(current_map + 1);
//        }
//        catch (std::exception const& ex)
//        {
//            player.sprite.move(1, 0);
//            fmt::println("Maps out of range");
//        }
//    }
//    else if(player.sprite.getPosition().x < 0)
//    {
//        try
//        {
//            platforms = change(current_map - 1);
//        }
//        catch (std::exception const& ex)
//        {
//            player.sprite.move(1, 0);
//            fmt::println("Maps out of range [index: (-1)]");
//        }
//    }
//    return platforms;
//
//}

std::vector<Platform> Map::change(int map)
{
    clock.restart();
    platforms.clear();
    current_map = map;
    for(auto & plat : platforms)
    {
        plat.generateObjects();
    }

    if(map == 0)
    {
        Platform platform0 = Platform(sf::Vector2f(window->getSize().x, window->getSize().y), sf::Vector2f(0, 550), "platform");
        platforms.push_back(platform0);
    }
    if(map == 1)
    {
        Platform platform0 = Platform(sf::Vector2f(200, window->getSize().y), sf::Vector2f(0, 550), "platform");
        Platform platform1 = Platform(sf::Vector2f(200, window -> getSize().y), sf::Vector2f(200,400), "platform1");
        Platform platform2 = Platform(sf::Vector2f(200, window->getSize().y), sf::Vector2f(400,300), "platform");
        Platform platform3 = Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 500), "platform");
        Platform platform4 = Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, 640), "lift");
        Platform platform5 = Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 900), "platform");
        Platform platform6 = Platform(sf::Vector2f(500, 60), sf::Vector2f(window->getSize().x - 200, window->getSize().y - 240), "platform");



        platforms.push_back(platform0);
        platforms.push_back(platform1);
        platforms.push_back(platform2);
        platforms.push_back(platform3);
        platforms.push_back(platform4);
        platforms.push_back(platform5);
        platforms.push_back(platform6);
    }
    else if(map == 2)
    {
        Platform platform0 = Platform(sf::Vector2f(500, 30), sf::Vector2f(-50, window->getSize().y - 240), "platform");
        Platform platform1 = Platform(sf::Vector2f(200, 20), sf::Vector2f(250,200), "platform");
        Platform platform2 = Platform(sf::Vector2f(200, 20), sf::Vector2f(550,500), "lift");
        Platform platform3 = Platform(sf::Vector2f(500, 20), sf::Vector2f(650, 920), "platform");
        Platform platform4 = Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, window -> getSize().y - 400), "lift");
        Platform platform5 = Platform(sf::Vector2f(500, 40), sf::Vector2f(1920 - 200, window -> getSize().y - 700), "platform");

        platforms.push_back(platform0);
        platforms.push_back(platform1);
        platforms.push_back(platform2);
        platforms.push_back(platform3);
        platforms.push_back(platform4);
        platforms.push_back(platform5);
    }
    else if(map == 3)
    {
        Platform platform0 = Platform(sf::Vector2f(500, 30), sf::Vector2f(-20, window->getSize().y - 700), "platform");
        Platform platform1 = Platform(sf::Vector2f(200, 30), sf::Vector2f(450,900), "platform1");
        Platform platform2 = Platform(sf::Vector2f(200, 30), sf::Vector2f(650,900), "platform");
        Platform platform3 = Platform(sf::Vector2f(500, 30), sf::Vector2f(450, 750), "platform");
        Platform platform4 = Platform(sf::Vector2f(200, 30), sf::Vector2f(1000, 720), "lift");
        Platform platform5 = Platform(sf::Vector2f(500, 30), sf::Vector2f(1200, 200), "platform");

        platforms.push_back(platform0);
        platforms.push_back(platform1);
        platforms.push_back(platform2);
        platforms.push_back(platform3);
        platforms.push_back(platform4);
        platforms.push_back(platform5);
    }

//    platforms.push_back(platform5);

    return platforms;


}

std::vector<std::vector<Platform>> Map::generateMaps()
{
    {
        Platform platform0 = Platform(sf::Vector2f(window->getSize().x, window->getSize().y), sf::Vector2f(0, 550), "platform");
        maps[0].push_back(platform0);
    }

    {
        Platform platform0 = Platform(sf::Vector2f(200, window->getSize().y), sf::Vector2f(0, 550), "platform");
        Platform platform1 = Platform(sf::Vector2f(200, window -> getSize().y), sf::Vector2f(200,400), "platform1");
        Platform platform2 = Platform(sf::Vector2f(200, window->getSize().y), sf::Vector2f(400,300), "platform");
        Platform platform3 = Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 500), "platform");
        Platform platform4 = Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, 640), "lift");
        Platform platform5 = Platform(sf::Vector2f(500, 40), sf::Vector2f(600, 900), "platform");
        Platform platform6 = Platform(sf::Vector2f(500, 60), sf::Vector2f(window->getSize().x - 200, window->getSize().y - 240), "platform");



        maps[1].push_back(platform0);
        maps[1].push_back(platform1);
        maps[1].push_back(platform2);
        maps[1].push_back(platform3);
        maps[1].push_back(platform4);
        maps[1].push_back(platform5);
        maps[1].push_back(platform6);
    }

    {
        Platform platform0 = Platform(sf::Vector2f(500, 30), sf::Vector2f(-50, window->getSize().y - 240), "platform");
        Platform platform1 = Platform(sf::Vector2f(200, 20), sf::Vector2f(250,200), "platform");
        Platform platform2 = Platform(sf::Vector2f(200, 20), sf::Vector2f(550,500), "lift");
        Platform platform3 = Platform(sf::Vector2f(500, 20), sf::Vector2f(650, 920), "platform");
        Platform platform4 = Platform(sf::Vector2f(500, 40), sf::Vector2f(1200, window -> getSize().y - 400), "lift");
        Platform platform5 = Platform(sf::Vector2f(500, 40), sf::Vector2f(1920 - 200, window -> getSize().y - 700), "platform");

        maps[2].push_back(platform0);
        maps[2].push_back(platform1);
        maps[2].push_back(platform2);
        maps[2].push_back(platform3);
        maps[2].push_back(platform4);
        maps[2].push_back(platform5);
    }

    {
        Platform platform0 = Platform(sf::Vector2f(500, 30), sf::Vector2f(-20, window->getSize().y - 700), "platform");
        Platform platform1 = Platform(sf::Vector2f(200, 30), sf::Vector2f(450,900), "platform1");
        Platform platform2 = Platform(sf::Vector2f(200, 30), sf::Vector2f(650,900), "platform");
        Platform platform3 = Platform(sf::Vector2f(500, 30), sf::Vector2f(450, 750), "platform");
        Platform platform4 = Platform(sf::Vector2f(200, 30), sf::Vector2f(1000, 720), "lift");
        Platform platform5 = Platform(sf::Vector2f(500, 30), sf::Vector2f(1200, 200), "platform");

        maps[3].push_back(platform0);
        maps[3].push_back(platform1);
        maps[3].push_back(platform2);
        maps[3].push_back(platform3);
        maps[3].push_back(platform4);
        maps[3].push_back(platform5);
    }

//    platforms.push_back(platform5);



}

//std::vector<Platform> Map::import(std::string path) {
//    std::fstream file;
//    file.open(path, std::ios::in);
//
//
//
//}