//
// Created by AMT on 25/03/2021.
//

#include "Entity.h"

Entity::Entity() {}

Entity::~Entity() noexcept {}

int Entity::GetX() const {
    return x;
}

void Entity::SetX(int _x) {
    Entity::x = _x;
}

int Entity::GetY() const {
    return y;
}

void Entity::SetY(int _y) {
    Entity::y = _y;
}

int Entity::GetLife() const {
    return life;
}

void Entity::SetLife(int _life) {
    Entity::life = _life;
}

void Entity::Update() {}

void Entity::Draw() {}