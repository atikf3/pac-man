#ifndef MONSTER_FACTORY_HH
#define MONSTER_FACTORY_HH

#include <string>
#include "Character.hh"
#include "ZombieMonster.hh"
#include "SprinterMonster.hh"

class MonsterFactory 
{
    public:
        MonsterFactory();
        ~MonsterFactory();
        Character* Create(const std::string&);
        Character* Unserialize(const std::string &json);
};

#endif