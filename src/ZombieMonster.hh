#ifndef ZOMBIE_MONSTER_HH
#define ZOMBIE_MONSTER_HH

#include "Character.hh"
#include "TimeManager.hh"

class ZombieMonster : public Character
{
    public:
        ZombieMonster();
        ~ZombieMonster();
        void Update();
};
#endif