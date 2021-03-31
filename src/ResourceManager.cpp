//
// Created by AMT on 27/03/2021.
//

#include "ResourceManager.h"

Console ResourceManager::console("ResourceManager");

ResourceManager *ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager() {
    if (_instance == nullptr) _instance = this;
}

sf::Texture &ResourceManager::getTexture(std::string const &filename) {
    console.print(std::string("getTexture(): loading ") + filename);
    auto &map = _instance->_textures;
    // Check if texture is loaded
    auto found = map.find(filename);
    if (found != map.end()) // Return texture
        return found->second;
    else {
        // Create texture
        auto &texture = map[filename];
        if (!texture.loadFromFile(ResourceManager::PATH_PREFIX + filename))
//            throw std::runtime_error("");
            throw std::runtime_error("getTexture() - Failed to load " + ResourceManager::PATH_PREFIX + filename);
        texture.setSmooth(true);
        return texture;
    }
}

int ResourceManager::loadTextures() {
    console.print("Loading textures...");
    try {
        ResourceManager::getTexture("img/map.png");
//        ResourceManager::getTexture("img/map.png");
    } catch (std::runtime_error e) {
        console.print(std::string("Runtime error: ") + e.what());
        return -1;
    }
    return 0;
}