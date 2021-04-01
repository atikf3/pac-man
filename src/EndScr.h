//
// Created by AMT on 09/03/2021.
//

#pragma once
#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "Console.h"
#include "ResourceManager.h"
#include <iostream>

#define MAX_ITEMS 3

class EndScreen {
public:
//    EndScreen(float width, float height);

    EndScreen(float width, float height, int pacmanLife);

    ~EndScreen();

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; };
    static int initEnd(sf::RenderWindow &window, int pacmanLife);
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_ITEMS];
    static Console console;

};