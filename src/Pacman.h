//
// Created by AMT on 25/03/2021.
//

#pragma once

#include "Entity.h"
#include "TileMap.h"

class Pacman : public Entity {
public:
    Pacman();
    ~Pacman();

    virtual void Update();
};

