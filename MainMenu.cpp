//
// Created by pete on 16.06.24.
//

#include "MainMenu.h"

void MainMenu::eventChooser(sf::Event &event, int &viewChooser)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(Utils::isTextClicked(startGameText, *window))
            {
                fmt::println("Starting The Game");
                viewChooser = 1;
            }
            else if(Utils::isTextClicked(endGameText, *window))
            {
                fmt::println("Goodbye");
                window -> close();
            }
        }

    }
}

void MainMenu::update()
{
    window->draw(text);
    window->draw(startGameText);
    window->draw(endGameText);
}