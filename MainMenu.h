//
// Created by pete on 16.06.24.
//

#ifndef DASHKING_MAINMENU_H
#define DASHKING_MAINMENU_H

#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Utils.h"

class MainMenu {

private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::Text text;
    sf::Text startGameText;
    sf::Text endGameText;
    sf::Font font;

public:
    MainMenu(sf::RenderWindow & main_window){

        window = std::unique_ptr<sf::RenderWindow>(&main_window);
        //MAIN MENU

        if( !font.loadFromFile("old_london/OldLondon.ttf"))
        {
            fmt::println("Error loading file");
            system("pause");
        }

        text.setFont(font);
        text.setString("Dash King");
        text.setCharacterSize(240);

        startGameText.setFont(font);
        startGameText.setString("Start");
        startGameText.setCharacterSize(120);
        startGameText.setFillColor(sf::Color::White);

        endGameText.setFont(font);
        endGameText.setString("End");
        endGameText.setCharacterSize(120);
        endGameText.setFillColor(sf::Color::White);

        sf::FloatRect textRect = text.getLocalBounds();
        sf::FloatRect textRect2 = startGameText.getLocalBounds();
        sf::FloatRect textRect3 = endGameText.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width/2.0f,
                       textRect.top  + textRect.height/2.0f);

        startGameText.setOrigin(textRect2.left + textRect2.width/2.0f,
                                textRect2.top  + textRect2.height/2.0f);

        endGameText.setOrigin(textRect3.left + textRect3.width/2.0f,
                              textRect3.top  + textRect3.height/2.0f);

        text.setPosition(sf::Vector2f(window->getSize().x/2.0f,window->getSize().y/4.0f));
        startGameText.setPosition(sf::Vector2f(window->getSize().x/2.0f,window->getSize().y/4.0f + 250));
        endGameText.setPosition(sf::Vector2f(window->getSize().x/2.0f,window->getSize().y/4.0f + 350));


    }
    void eventChooser(sf::Event & event, int & viewChooser);

    void update();
};


#endif //DASHKING_MAINMENU_H
