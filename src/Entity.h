//
// Created by AMT on 25/03/2021.
//

#pragma once


#include "AbstractEntity.hh"

class Entity : AbstractEntity {
protected:
    Entity();
    virtual ~Entity();

public:
    int x;
    int y;
    int life;
    int GetX() const;
    void SetX(int _x);
    int GetY() const;
    void SetY(int _y);
    int GetLife() const;
    void SetLife(int _life);
    void virtual Update();
    void virtual Draw();
};

