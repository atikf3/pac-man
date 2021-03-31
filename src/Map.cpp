//
// Created by AMT on 24/03/2021.
//

#include "Map.h"

Map::~Map(){}

Console Map::console("Map");

Map::Map(float width) {
    if(!font.loadFromFile(FONT_PATH)){
        std::cout << "Font error Map" << std::endl;
    }
    text[0].setFont(font);
    text[0].setFillColor(sf::Color::White);
    text[0].setString("Time");
    text[0].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 1, 0));

    text[2].setFont(font);
    text[2].setFillColor(sf::Color::White);
    text[2].setString("Score");
    text[2].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 3, 0));

    text[4].setFont(font);
    text[4].setFillColor(sf::Color::White);
    text[4].setString("FPS");
    text[4].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 5, 0));
}

int Map::MapRenderer(sf::RenderWindow &w, Map map) {
int level[31][28] = {
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,3,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,3,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
                {0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
                {0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
                {0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0},
                {1,1,1,1,1,0,2,0,0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,0,0,0,7,7,0,0,0,1,0,0,2,0,1,1,1,1,1},
                {0,0,0,0,0,0,2,0,0,1,0,1,1,1,1,1,1,0,1,0,0,2,0,0,0,0,0,0},
                {6,1,1,1,1,1,2,1,1,1,0,1,1,1,1,1,1,0,1,1,1,2,1,1,1,1,1,6},
                {0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0},
                {1,1,1,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0,1,1,1,1,1},
                {1,1,1,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,1,1,1,1,1},
                {0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
                {0,3,2,2,0,0,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,0,0,2,2,3,0},
                {0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
                {0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
                {0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
                {0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
                {0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
        };
//    ResourceManager manager;
//    manager.loadTextures();
    sf::Sprite background(ResourceManager::getTexture(MAP_BG));
    background.setOrigin(0, -50);
//    if (!tileGums.load(MAP_TILESET_GUMS_PATH, sf::Vector2u(16, 16), level, 28, 31))
//        std::cout << "Gums Tilemap error" << std::endl;
////    w = 31;
//    h = 28;
//    m[w][h];
//    static TimeManager& instance = TimeManager::GetInstance();
//    static FPS& fps = FPS::GetInstanceFPS();
//    Balls balls;
//    Pinky pinky;
//    Blinky blinky;
//    Inky inky;
//    Clyde clyde;
    Pacman pacman;
//    instance.Start();
//    int i;
    while (w.isOpen()) {
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w.close();
            else if (e.type == sf::Event::KeyPressed) {
                switch (e.key.code) {
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Key::W:
                    case sf::Keyboard::Key::Z:
                        if(level[pacman.GetY() - 1][pacman.GetX()] != 0)
                            pacman.SetY(pacman.GetY() - 1);
//                        balls.BallsWasEat(level[pacman.GetY()][pacman.GetX()], scores, gameStatus);
                        level[pacman.GetY()][pacman.GetX()] = 1;

                        console.print("Pacman went up (KeyEvent, Y - 1)");
                        break;
                    case sf::Keyboard::Down:
                    case sf::Keyboard::Key::S:
                        if(level[pacman.GetY() + 1][pacman.GetX()] != 0)
                            pacman.SetY(pacman.GetY() + 1);
//                        balls.BallsWasEat(level[pacman.GetY()][pacman.GetX()], scores, gameStatus);
                        level[pacman.GetY()][pacman.GetX()] = 1;

                        console.print("Pacman went down (KeyEvent, X + 1)");
                        break;
                    case sf::Keyboard::Left:
                    case sf::Keyboard::Key::A:
                    case sf::Keyboard::Key::Q:
                        if(level[pacman.GetY()][pacman.GetX() - 1] != 0)
                            pacman.SetX(pacman.GetX() - 1);
                        level[pacman.GetY()][pacman.GetX()] = 1;

                        console.print("Pacman went left (KeyEvent, X - 1)");
                        break;
                    case sf::Keyboard::Right:
                    case sf::Keyboard::Key::D:
                        if(level[pacman.GetY()][pacman.GetX() + 1] != 0)
                            pacman.SetX(pacman.GetX() + 1);
                        level[pacman.GetY()][pacman.GetX()] = 1;
                        console.print("Pacman went right (KeyEvent, X + 1)");
                        break;
                }
                console.print("Pacman at X: " + std::to_string(pacman.GetX()) + " Y: " + std::to_string(pacman.GetY()));
            }
        }
        if (!tileGums.load(MAP_TILESET_GUMS_PATH, sf::Vector2u(16, 16), level, 28, 31))
            std::cout << "TileMap Error" << std::endl;
        if (!tilePacman.move(MAP_TILESET_PACMAN_PATH, sf::Vector2u(16, 16), pacman.GetX(), pacman.GetY()))
            return -1;
        w.clear();
//        w.draw(sprite);
        w.draw(background);
        w.draw(tileGums);
        w.draw(tilePacman);
        map.RenderHeader(w, 0, 1, 2);
        w.display();
        sleep(0.1);
    }

    return 0;
}


void Map::RenderHeader(sf::RenderWindow &window, int score, int time, int fps) {
    for(int i = 0; i < MAX_NUMBER_OF_ITEMS_MAP; i++) {
        window.draw(text[i]);
        text[1].setFont(font);
        text[1].setFillColor(sf::Color::White);
        text[1].setString(std::to_string(time));
        text[1].setPosition(sf::Vector2f(window.getSize().x /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 2, 0));

        text[3].setFont(font);
        text[3].setFillColor(sf::Color::White);
        text[3].setString(std::to_string(score));
        text[3].setPosition(sf::Vector2f(window.getSize().x /(MAX_NUMBER_OF_ITEMS_MAP) * 4, 0));

        text[5].setFont(font);
        text[5].setFillColor(sf::Color::White);
        text[5].setString(std::to_string(fps));
        text[5].setPosition(sf::Vector2f(window.getSize().x /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 6, 0));
    }
}
