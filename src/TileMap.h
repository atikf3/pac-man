//
// Created by AMT on 24/03/2021.
//

#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "ResourceManager.h"

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string &tileset, sf::Vector2u tileSize, const int tiles[31][28], unsigned int width, unsigned int height);
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
    int move(const std::string& tileset, sf::Vector2u tileSize, int x, int y);
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};