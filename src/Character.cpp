#include "Character.hh"

Character::~Character()
{
}

void Character::Draw()
{
}

void Character::Update()
{
}

void Character::SetX(double x)
{
    _x = x;
    for (auto obs : _observers)
        obs->Notify(this);
}

void Character::SetY(double y)
{
    _y = y;
     for (auto obs : _observers)
        obs->Notify(this);
}

double Character::GetX() const
{
    return _x;
}

double Character::GetY() const
{
    return _y;
}

void Character::SetLife(int life)
{
    _life = life;
    for (auto obs : _observers)
        obs->Notify(this);
}

int Character::GetLife() const
{
    return _life;
}

void    Character::AddObserver(IObserver *observer)
{
    _observers.push_front(observer);
}

void    Character::RemoveObserver(IObserver *observer)
{
    _observers.remove(observer);
}

std::string Character::Serialize()
{
    json object;

    object["type"] = _type;
    object["x"] = _x;
    object["y"] = _y;
    object["life"] = _life;

    return object.dump();
}
