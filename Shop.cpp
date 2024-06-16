//
// Created by pete on 16.06.24.
//

#include "Shop.h"

void Shop::eventChooser(sf::Event &event, int &viewChooser)
{
    saveShopCart();
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(event.mouseButton.button == sf::Mouse::Left) {
            if (Utils::isTextClicked(start, *window)) {
                fmt::println("Starting The Game");
                viewChooser = 2;
            } else if (Utils::isTextClicked(goBack, *window)) {
                fmt::println("Goodbye");
                viewChooser--;
            }
            for (auto &i: shopItems) {

                if (Utils::isTextClicked(i.second, *window)) {
                    fmt::println("{}", fullShopMap[i.first]);
                    if (current_coins >= fullShopMap[i.first]) {
                        fmt::println("Kupiles to");
                        current_coins = current_coins - fullShopMap[i.first];
                        jsonData["coins"] = current_coins;
                        currentAmount.setString(std::to_string(current_coins));
                        auto it = shop_cart.find(i.first);
                        if (it != shop_cart.end()) {
                            shop_cart.insert({i.first, 1});
                        } else {
                            shop_cart[i.first]++;
                        }

                    } else {
                        fmt::println("Nie stać cię na to");
                    }
                }
            }


        }
    }
}

void Shop::saveShopCart()
{
    nlohmann::json jsonNew;
    jsonNew = jsonData;

    for(auto & i : shop_cart)
    {
        fmt::println("{} : {}", i.first, i.second);

        if(i.first == "heart")
        {
            jsonNew["hearts"] = int(jsonNew["hearts"]) + i.second;
        }

        if(i.first == "x2 coins")
        {
            jsonNew["multiplier"] = int(jsonNew["multiplier"]) + i.second;
        }

        if(i.first == "speed")
        {
            jsonNew["xVelocity"] = int(jsonNew["xVelocity"]) + i.second;
        }

        if(i.first == "stamina")
        {
            jsonNew["stamina"] = int(jsonNew["stamina"]) + i.second;
        }
    }

    std::ofstream jsonOut("./Player.json");
    jsonOut << std::setw(4) << jsonNew << std::endl;
    jsonOut.close();

}
void Shop::update()
{

    for(auto & t : otherText)
    {
        window -> draw(*t);
    }

    for(auto & item : shopItemsPrice)
    {
        window->draw(item.second);
    }
    for(auto & item : shopItems)
    {
        window->draw(item.second);
    }

}