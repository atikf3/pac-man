//
// Created by AMT on 24/03/2021.
//

#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include "TileMap.h"
#include "Console.h"
#include "ResourceManager.h"
#include "Pacman.h"
#include "FPS.h"
#include "GameState.h"
#include "EndScr.h"
#include "TimeManager.hh"

#define MAX_NUMBER_OF_ITEMS_MAP 6
#define FONT_PATH "../src/assets/fonts/Roboto-Regular.ttf"
#define MAP_BG_PATH "../src/assets/img/map.png"
#define MAP_TILESET_GUMS_PATH "../src/assets/tileset/tile_gum.png"
#define MAP_TILESET_PACMAN_PATH "../src/assets/img/pacman.png"
#define MAP_TILESET_INKY "../src/assets/img/inky.png"

class Map {
public:
    Map(float width);
    virtual ~Map();
    sf::Texture texture;
    TileMap tileGums;
    TileMap tilePacman;
    TileMap jaunefantome;
    sf::Sprite sprite;
    int level[31][28];
    int MapRenderer(sf::RenderWindow &w, Map map);
    bool positionValide(int x , int y);

    int gums;
    int location;
    int score;
protected:
    sf::Font font;
    sf::Text text[MAX_NUMBER_OF_ITEMS_MAP];
    sf::Event e;
    void RenderHeader(sf::RenderWindow &window, int score, int time, int fps);

private:
    static Console console;
    void HandleGumEat(int where);
};