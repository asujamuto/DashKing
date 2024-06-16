//
// Created by pete on 16.06.24.
//
#pragma once
#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Utils.h"
#include <unordered_map>
#include <algorithm>
#include <nlohmann/json.hpp>

class Shop {

private:
    std::unique_ptr<sf::RenderWindow> window;
    sf::Text welcome;
    sf::Text subWelcome;
    sf::Text start;
    sf::Text currentAmountText;
    sf::Text currentAmount;
    sf::Text currentHeartsAmountText;
    sf::Text currentHeartsAmount;
    sf::Text goBack;
    std::vector<sf::Text*> otherText;

    std::map<std::string, int> shop_cart;

    sf::Font font;
    std::unordered_map<std::string, sf::Text> shopItems;
    std::unordered_map<int, sf::Text> shopItemsPrice;

    std::unordered_map<std::string, int> fullShopMap;

    nlohmann::json jsonData;

    int current_hearts;
    int current_coins;
public:
    Shop(sf::RenderWindow & main_window){

        //Code from https://www.youtube.com/watch?v=NuWQp_uAvwo
        std::ifstream jsonFileStream("Player.json");
        jsonData = nlohmann::json::parse(jsonFileStream);


        window = std::unique_ptr<sf::RenderWindow>(&main_window);
        //MAIN MENU

        if( !font.loadFromFile("old_london/OldLondon.ttf"))
        {
            fmt::println("Error loading file");
            system("pause");
        }
        current_hearts = jsonData["hearts"];
        current_coins = jsonData["coins"];

        std::string hearts = std::to_string(current_hearts);
        std::string coins = std::to_string(current_coins);

        otherText.emplace_back(&welcome);
        otherText.emplace_back(&subWelcome);
        otherText.emplace_back(&currentAmountText);
        otherText.emplace_back(&currentAmount);
        otherText.emplace_back(&currentHeartsAmountText);
        otherText.emplace_back(&currentHeartsAmount);
        otherText.emplace_back(&start);
        otherText.emplace_back(&goBack);

        welcome.setString("Welcome to the Royal Shop");

        subWelcome.setString("Choose item to buy or go to the dungeon");

        currentAmountText.setString("Current Coins Amount: ");
        currentAmount.setString(coins);

        currentHeartsAmountText.setString("Current Hearts Amount: ");
        currentHeartsAmount.setString(hearts);

        start.setString("Go to the Dungeon");

        goBack.setString("Go back");

        for(auto & text : otherText)
        {
            text->setFont(font);
            text->setCharacterSize(60);
            text->setFillColor(sf::Color::White);

            sf::FloatRect textRect = text->getLocalBounds();

            text->setOrigin(textRect.left + textRect.width/2.0f,
                              textRect.top  + textRect.height/2.0f);
        }



        welcome.setPosition(sf::Vector2f(window->getSize().x/2.0f,window->getSize().y/4.0f- 50));
        subWelcome.setPosition(sf::Vector2f(window->getSize().x/2.0f, window->getSize().y/4.0f + welcome.getCharacterSize() - 50));

        currentAmountText.setPosition(sf::Vector2f(window->getSize().x - 200, 100));
        currentAmountText.setCharacterSize(20);
        currentAmount.setPosition(sf::Vector2f(window->getSize().x - 200, 100));
        currentAmount.setCharacterSize(20);

        currentHeartsAmountText.setPosition(sf::Vector2f(window->getSize().x - 200, 120));
        currentHeartsAmountText.setCharacterSize(20);
        currentHeartsAmount.setPosition(sf::Vector2f(window->getSize().x - 200, 120));
        currentHeartsAmount.setCharacterSize(20);


        start.setPosition(sf::Vector2f(window->getSize().x/2.0f,window->getSize().y - 400 - goBack.getCharacterSize()));
        goBack.setPosition(sf::Vector2f(window->getSize().x/2.0f,window->getSize().y - 350 + start.getCharacterSize()));


        fullShopMap.insert({"heart", 20});
        fullShopMap.insert({"stamina", 30});
        fullShopMap.insert({"speed", 40});
        fullShopMap.insert({"x2 coins", 120});

//        for(int i = 0; i < fullShop.size(); i++)
//        {
//            shopItems.insert({fullShop[i].first, sf::Text()});
//            shopItemsPrice.insert({fullShop[i].second, sf::Text()});
//        }

        for(const auto m : fullShopMap)
        {
            shopItems.insert({m.first, sf::Text()});
            shopItemsPrice.insert({m.second, sf::Text()});
        }





        int gap = 50;
        for(auto & item : shopItems)
        {
            item.second.setFont(font);
            item.second.setString(item.first);
            item.second.setCharacterSize(60);
            item.second.setFillColor(sf::Color::White);
            sf::FloatRect itemRect = item.second.getLocalBounds();
            item.second.setOrigin(itemRect.left + itemRect.width/2.0f,
                              itemRect.top  + itemRect.height/2.0f);
            item.second.setPosition(sf::Vector2f(window->getSize().x/2.0f,
                                                 window->getSize().y/4.0f + item.second.getCharacterSize() + gap));

            gap += 50;
        }


        gap = 50;
        for(auto & item : shopItemsPrice)
        {
            item.second.setFont(font);
            item.second.setString(std::to_string(item.first));
            item.second.setCharacterSize(60);
            item.second.setFillColor(sf::Color::White);
            sf::FloatRect itemRect = item.second.getLocalBounds();
            item.second.setOrigin(itemRect.left + itemRect.width/2.0f,
                                  itemRect.top  + itemRect.height/2.0f);
            item.second.setPosition(sf::Vector2f(window->getSize().x/2.0f + 420,
                                                 window->getSize().y/4.0f + item.second.getCharacterSize() + gap));
            gap += 50;

        }


    }
    void eventChooser(sf::Event & event, int & viewChooser);

    void update();

    void saveShopCart();
    ~Shop()
    {
        for(auto o : otherText)
        {
            delete o;

        }
    }

};