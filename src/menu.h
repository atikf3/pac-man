//
// Created by AMT on 09/03/2021.
//

#pragma once
#include "SFML/Graphics.hpp"
#include "console.h"
#include "ResourceManager.h"
#include "map.h"
#include <iostream>

#define MAX_ITEMS 3

class Menu {
    public:
        Menu(float width, float height);
        ~Menu();

        void draw(sf::RenderWindow& window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() { return selectedItemIndex; };
        static int initMenu(sf::RenderWindow &window);
private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_ITEMS];
        static Console console;

};