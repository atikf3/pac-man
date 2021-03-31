//
// Created by AMT on 24/03/2021.
//

#include "TileMap.h"

bool TileMap::load(const std::string& tileset, sf::Vector2u tileSize, const int tiles[31][28], unsigned int width, unsigned int height) {
    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;

    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j) {
            // on récupère le numéro de tuile courant
            int tileNumber = tiles[i][j/** width*/];

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y + 50);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y + 50);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y + 50);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y + 50);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}


void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
}

int TileMap::move(const std::string& tileset, sf::Vector2u tileSize, int x, int y) {
    if (!m_tileset.loadFromFile(tileset))
        return 0;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(30 * 30 * 4);

    int tu = 0 % (m_tileset.getSize().x / tileSize.x);
    int tv = 0 / (m_tileset.getSize().x / tileSize.x);

    sf::Vertex* quad = &m_vertices[( 28) * 4];

    quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y +50);
    quad[1].position = sf::Vector2f((x + 1) * tileSize.x, y * tileSize.y +50);
    quad[2].position = sf::Vector2f((x + 1) * tileSize.x, (y + 1) * tileSize.y +50);
    quad[3].position = sf::Vector2f(x * tileSize.x, (y + 1) * tileSize.y +50);

    quad[0].texCoords = sf::Vector2f(0,0);//tu * tileSize.x, tv * tileSize.y);
    quad[1].texCoords = sf::Vector2f(16,0);//(tu + 1) * tileSize.x, tv * tileSize.y);
    quad[2].texCoords = sf::Vector2f(16,16);//(tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    quad[3].texCoords = sf::Vector2f(0,16);//stu * tileSize.x, (tv + 1) * tileSize.y);

    return 1;
}