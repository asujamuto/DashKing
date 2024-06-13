//
// Created by pete on 10.06.24.
//

#ifndef DASHKING_GAMEOBJECT_H
#define DASHKING_GAMEOBJECT_H

#pragma once
#include <SFML/Graphics.hpp>

template <typename T>
class GameObject {


    public:
        T shape;

        GameObject(const sf::Vector2f size, const sf::Vector2f position)
        {
            shape = sf::RectangleShape(size);
            shape.setPosition(position);
            shape.setFillColor(sf::Color::Blue);
        }

        //circle
        GameObject(float radius, sf::Vector2f position)
        {
            shape = sf::CircleShape(radius);
            shape.setPosition(position);
            shape.setFillColor(sf::Color::Blue);
        }

        GameObject(float radius, sf::Vector2f position, int point)
        {
            shape = sf::CircleShape(radius, point);
            shape.setPosition(position);
            shape.setFillColor(sf::Color::Blue);
        }
};


#endif //DASHKING_GAMEOBJECT