//
// Created by AMT on 27/03/2021.
//

#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include "Console.h"

#define FONT_PATH "fonts/Roboto-Regular.ttf"
#define MAP_BG "img/map.png"
#define MAP_TILESET_GUMS_PATH "tileset/tile_gum.png"
#define MAP_TILESET_PACMAN_PATH "img/pacman.png"

class ResourceManager {
public:
    ResourceManager();
    static sf::Texture &getTexture(std::string const &filename);
    inline static const std::string PATH_PREFIX = "../src/assets/";
    static int loadTextures();
private:
    std::map<std::string, sf::Texture> _textures;
    static Console console;
    static ResourceManager *_instance;
};
