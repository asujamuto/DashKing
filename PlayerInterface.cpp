//
// Created by pete on 23.05.24.
//


#include "PlayerInterface.h"

#include "PlayerInterface.h"

PlayerInterface::PlayerInterface(sf::Window const& main_window)
{
    for(int i = 0; i < hearts.size(); i++ )
    {
        hearts[i] -> setPosition(sf::Vector2f(200,200 + (i * 100)));
    }



};

PlayerInterface::~PlayerInterface()
{

    for(auto heart : hearts)
    {
       delete heart;
    };

}