//
// Created by AMT on 27/03/2021.
//

#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include "Console.h"

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
